# 🍃 Part 6 — MongoDB + Mongoose with TypeScript

> Ye MERN developers ke liye sabse important part hai

---

## 6.1 Setup

```bash
npm install mongoose
npm install -D @types/mongoose   # Mongoose v6+ mein built-in types hain
```

---

## 6.2 Model Banana — Sahi Tarika

```typescript
import { Schema, model, Document, Types } from 'mongoose'

// ===== Step 1: Interface banao =====

export interface IUser {
  name: string
  email: string
  password: string
  role: 'admin' | 'user' | 'moderator'
  isActive: boolean
  createdAt: Date
  updatedAt: Date
}

// ===== Step 2: Document type (Mongoose ke methods ke saath) =====

export interface IUserDocument extends IUser, Document {
  // Custom methods yahan aate hain
  comparePassword(password: string): Promise<boolean>
  getPublicProfile(): Omit<IUser, 'password'>
}

// ===== Step 3: Schema banao =====

const userSchema = new Schema<IUserDocument>(
  {
    name: {
      type: String,
      required: [true, 'Naam required hai'],
      trim: true,
      minlength: [2, 'Naam kam se kam 2 characters ka hona chahiye']
    },
    email: {
      type: String,
      required: [true, 'Email required hai'],
      unique: true,
      lowercase: true,
      match: [/^\S+@\S+\.\S+$/, 'Valid email do']
    },
    password: {
      type: String,
      required: true,
      minlength: 8,
      select: false   // Default queries mein password nahi aayega
    },
    role: {
      type: String,
      enum: ['admin', 'user', 'moderator'],
      default: 'user'
    },
    isActive: {
      type: Boolean,
      default: true
    }
  },
  {
    timestamps: true   // createdAt, updatedAt automatic
  }
)

// ===== Step 4: Methods add karo =====

userSchema.methods.comparePassword = async function(
  candidatePassword: string
): Promise<boolean> {
  // bcrypt compare yahan
  return candidatePassword === this.password  // real mein bcrypt use karo
}

userSchema.methods.getPublicProfile = function(): Omit<IUser, 'password'> {
  const { password, ...publicData } = this.toObject()
  return publicData
}

// ===== Step 5: Model export karo =====

export const User = model<IUserDocument>('User', userSchema)
```

---

## 6.3 Relationships — Ref aur Populate

```typescript
// ===== Post model (User ke saath relation) =====

export interface IPost {
  title: string
  content: string
  author: Types.ObjectId   // Reference
  tags: string[]
  likes: Types.ObjectId[]  // Multiple references
  createdAt: Date
}

export interface IPostDocument extends IPost, Document {}

// Populated post (jab populate karte ho)
export interface IPostPopulated extends Omit<IPost, 'author'> {
  author: IUserDocument   // ObjectId ki jagah full user
}

const postSchema = new Schema<IPostDocument>({
  title: { type: String, required: true },
  content: { type: String, required: true },
  author: {
    type: Schema.Types.ObjectId,
    ref: 'User',
    required: true
  },
  tags: [{ type: String }],
  likes: [{ type: Schema.Types.ObjectId, ref: 'User' }]
}, { timestamps: true })

export const Post = model<IPostDocument>('Post', postSchema)
```

---

## 6.4 Service Layer — Controller se Mongoose alag rakho

`src/services/user.service.ts`:
```typescript
import { User, IUser, IUserDocument } from '../models/user.model'
import { Types } from 'mongoose'

// ===== Create =====

export const createUser = async (
  userData: Omit<IUser, 'createdAt' | 'updatedAt' | 'isActive'>
): Promise<IUserDocument> => {
  const user = new User(userData)
  await user.save()
  return user
}

// ===== Find All =====

export const getAllUsers = async (): Promise<IUserDocument[]> => {
  return User.find({ isActive: true }).select('-password')
}

// ===== Find by ID =====

export const getUserById = async (
  id: string
): Promise<IUserDocument | null> => {
  if (!Types.ObjectId.isValid(id)) {
    throw new Error('Invalid ID format')
  }
  return User.findById(id).select('-password')
}

// ===== Find by Email =====

export const getUserByEmail = async (
  email: string
): Promise<IUserDocument | null> => {
  return User.findOne({ email }).select('+password')  // password bhi chahiye login ke liye
}

// ===== Update =====

export const updateUser = async (
  id: string,
  updates: Partial<IUser>
): Promise<IUserDocument | null> => {
  return User.findByIdAndUpdate(
    id,
    { $set: updates },
    { new: true, runValidators: true }  // updated document return karo
  ).select('-password')
}

// ===== Delete (Soft) =====

export const deleteUser = async (id: string): Promise<void> => {
  await User.findByIdAndUpdate(id, { isActive: false })
}

// ===== Paginated Query =====

interface PaginationOptions {
  page: number
  limit: number
  sortBy?: keyof IUser
  sortOrder?: 'asc' | 'desc'
}

interface PaginatedResult<T> {
  data: T[]
  total: number
  page: number
  totalPages: number
}

export const getUsersPaginated = async (
  options: PaginationOptions
): Promise<PaginatedResult<IUserDocument>> => {
  const { page = 1, limit = 10, sortBy = 'createdAt', sortOrder = 'desc' } = options

  const skip = (page - 1) * limit
  const sort = { [sortBy]: sortOrder === 'asc' ? 1 : -1 }

  const [data, total] = await Promise.all([
    User.find({ isActive: true })
      .select('-password')
      .sort(sort as any)
      .skip(skip)
      .limit(limit),
    User.countDocuments({ isActive: true })
  ])

  return {
    data,
    total,
    page,
    totalPages: Math.ceil(total / limit)
  }
}
```

---

## 6.5 Controller — Service use karo

`src/controllers/user.controller.ts`:
```typescript
import { Request, Response } from 'express'
import * as userService from '../services/user.service'

export const getUsers = async (req: Request, res: Response): Promise<void> => {
  try {
    const page = parseInt(req.query.page as string) || 1
    const limit = parseInt(req.query.limit as string) || 10

    const result = await userService.getUsersPaginated({ page, limit })

    res.json({
      success: true,
      data: result.data,
      pagination: {
        page: result.page,
        total: result.total,
        totalPages: result.totalPages
      },
      message: 'Users fetched'
    })
  } catch (error) {
    res.status(500).json({
      success: false,
      message: error instanceof Error ? error.message : 'Server error'
    })
  }
}
```

---

## 6.6 Database Connection — Properly Typed

`src/config/database.ts`:
```typescript
import mongoose from 'mongoose'

interface DatabaseConfig {
  uri: string
  options?: mongoose.ConnectOptions
}

export const connectDatabase = async (config: DatabaseConfig): Promise<void> => {
  try {
    await mongoose.connect(config.uri, config.options)
    console.log('MongoDB connected ✅')
  } catch (error) {
    console.error('MongoDB connection failed:', error)
    process.exit(1)
  }
}

// Connection events
mongoose.connection.on('disconnected', () => {
  console.log('MongoDB disconnected')
})

mongoose.connection.on('error', (err) => {
  console.error('MongoDB error:', err)
})
```

`src/index.ts` mein use karo:
```typescript
import { connectDatabase } from './config/database'

connectDatabase({
  uri: process.env.MONGO_URI || 'mongodb://localhost:27017/mydb'
})
```

---

## ✅ Common Mongoose + TS Patterns

```typescript
// ===== ObjectId se string compare karna =====
const isOwner = post.author.toString() === userId

// ===== Type assertion for populated fields =====
const post = await Post.findById(id).populate<{ author: IUserDocument }>('author')
// Ab post.author.name direct accessible hai

// ===== Lean queries (plain JS object, faster) =====
const users = await User.find().lean<IUser[]>()
// _id, __v etc. manually type karna padega

// ===== Update return type =====
const updated = await User.findByIdAndUpdate(
  id,
  { name: 'New Name' },
  { new: true }
) as IUserDocument | null
```

---

## ✅ Checklist

- [ ] Interface + Document type banana aata hai
- [ ] Schema mein proper types use kar sakta hoon
- [ ] Service layer alag rakha
- [ ] Populate ke baad proper typing hai
- [ ] Pagination implement kar sakta hoon
