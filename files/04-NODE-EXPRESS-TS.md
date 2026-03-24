# 🌐 Part 4 — Node.js + Express with TypeScript

> Tumhara Express backend properly type karna

---

## 4.1 Project Setup

```bash
mkdir express-ts-api && cd express-ts-api
npm init -y
npm install express cors dotenv
npm install -D typescript ts-node nodemon @types/node @types/express @types/cors
npx tsc --init
```

Folder structure:
```
src/
├── index.ts           # Entry point
├── routes/
│   ├── user.routes.ts
│   └── product.routes.ts
├── controllers/
│   ├── user.controller.ts
│   └── product.controller.ts
├── middleware/
│   └── auth.middleware.ts
├── types/
│   └── index.ts       # Sab shared types yahan
└── models/
    └── (Mongoose models — Part 6 mein)
```

---

## 4.2 Types File — Pehle Yahan Se Shuru Karo

`src/types/index.ts`:
```typescript
// ===== API Response Type =====
export interface ApiResponse<T = unknown> {
  success: boolean
  data?: T
  message: string
  error?: string
}

// ===== User Types =====
export interface IUser {
  id: string
  name: string
  email: string
  role: 'admin' | 'user' | 'moderator'
  createdAt: Date
}

export type CreateUserDTO = Omit<IUser, 'id' | 'createdAt'> & {
  password: string
}

export type UpdateUserDTO = Partial<Omit<IUser, 'id' | 'createdAt'>>

// ===== Product Types =====
export interface IProduct {
  id: string
  name: string
  price: number
  category: string
  inStock: boolean
}

export type CreateProductDTO = Omit<IProduct, 'id'>

// ===== JWT Payload =====
export interface JwtPayload {
  userId: string
  email: string
  role: string
}

// ===== Express Request extend karo (auth ke baad) =====
declare global {
  namespace Express {
    interface Request {
      user?: JwtPayload   // req.user available ho jaata hai
    }
  }
}
```

---

## 4.3 Express App Setup

`src/index.ts`:
```typescript
import express from 'express'
import cors from 'cors'
import userRoutes from './routes/user.routes'
import productRoutes from './routes/product.routes'

const app = express()
const PORT = process.env.PORT || 3000

app.use(cors())
app.use(express.json())

// Routes
app.use('/api/users', userRoutes)
app.use('/api/products', productRoutes)

// Health check
app.get('/health', (req, res) => {
  res.json({ status: 'ok', timestamp: new Date() })
})

app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`)
})

export default app
```

---

## 4.4 Controller — Properly Typed

`src/controllers/user.controller.ts`:
```typescript
import { Request, Response, NextFunction } from 'express'
import { ApiResponse, IUser, CreateUserDTO, UpdateUserDTO } from '../types'

// Fake data — Mongoose wala Part 6 mein
const users: IUser[] = [
  {
    id: '1',
    name: 'Rahul Kumar',
    email: 'rahul@gmail.com',
    role: 'user',
    createdAt: new Date()
  }
]

// ===== GET /users =====
export const getAllUsers = async (
  req: Request,
  res: Response<ApiResponse<IUser[]>>  // Response type bhi specify karo
): Promise<void> => {
  try {
    res.json({
      success: true,
      data: users,
      message: 'Users fetched successfully'
    })
  } catch (error) {
    res.status(500).json({
      success: false,
      message: 'Server error',
      error: error instanceof Error ? error.message : 'Unknown error'
    })
  }
}

// ===== GET /users/:id =====
export const getUserById = async (
  req: Request<{ id: string }>,    // params ka type
  res: Response<ApiResponse<IUser>>
): Promise<void> => {
  const { id } = req.params
  const user = users.find(u => u.id === id)

  if (!user) {
    res.status(404).json({ success: false, message: 'User not found' })
    return
  }

  res.json({ success: true, data: user, message: 'User found' })
}

// ===== POST /users =====
export const createUser = async (
  req: Request<{}, {}, CreateUserDTO>,  // body ka type
  res: Response<ApiResponse<IUser>>
): Promise<void> => {
  const { name, email, role } = req.body

  if (!name || !email) {
    res.status(400).json({ success: false, message: 'Name aur email required hai' })
    return
  }

  const newUser: IUser = {
    id: String(users.length + 1),
    name,
    email,
    role: role || 'user',
    createdAt: new Date()
  }

  users.push(newUser)
  res.status(201).json({ success: true, data: newUser, message: 'User created' })
}

// ===== PATCH /users/:id =====
export const updateUser = async (
  req: Request<{ id: string }, {}, UpdateUserDTO>,
  res: Response<ApiResponse<IUser>>
): Promise<void> => {
  const { id } = req.params
  const index = users.findIndex(u => u.id === id)

  if (index === -1) {
    res.status(404).json({ success: false, message: 'User not found' })
    return
  }

  users[index] = { ...users[index], ...req.body }
  res.json({ success: true, data: users[index], message: 'User updated' })
}

// ===== DELETE /users/:id =====
export const deleteUser = async (
  req: Request<{ id: string }>,
  res: Response<ApiResponse<null>>
): Promise<void> => {
  const { id } = req.params
  const index = users.findIndex(u => u.id === id)

  if (index === -1) {
    res.status(404).json({ success: false, message: 'User not found' })
    return
  }

  users.splice(index, 1)
  res.json({ success: true, data: null, message: 'User deleted' })
}
```

---

## 4.5 Routes

`src/routes/user.routes.ts`:
```typescript
import { Router } from 'express'
import {
  getAllUsers,
  getUserById,
  createUser,
  updateUser,
  deleteUser
} from '../controllers/user.controller'

const router = Router()

router.get('/', getAllUsers)
router.get('/:id', getUserById)
router.post('/', createUser)
router.patch('/:id', updateUser)
router.delete('/:id', deleteUser)

export default router
```

---

## 4.6 Middleware — Auth Middleware

`src/middleware/auth.middleware.ts`:
```typescript
import { Request, Response, NextFunction } from 'express'
import { JwtPayload } from '../types'

// Simple auth middleware (JWT properly Part 7 mein)
export const authMiddleware = (
  req: Request,
  res: Response,
  next: NextFunction
): void => {
  const token = req.headers.authorization?.split(' ')[1]

  if (!token) {
    res.status(401).json({ success: false, message: 'Token required' })
    return
  }

  // Token verify karo — yahan JWT logic aayega
  const fakePayload: JwtPayload = {
    userId: '1',
    email: 'user@example.com',
    role: 'user'
  }

  req.user = fakePayload   // types/index.ts mein extend kiya tha
  next()
}

// Role-based middleware
export const requireRole = (role: string) => {
  return (req: Request, res: Response, next: NextFunction): void => {
    if (!req.user || req.user.role !== role) {
      res.status(403).json({ success: false, message: 'Permission denied' })
      return
    }
    next()
  }
}
```

---

## 4.7 Error Handling — Global

`src/middleware/error.middleware.ts`:
```typescript
import { Request, Response, NextFunction } from 'express'

// Custom Error class
export class AppError extends Error {
  public statusCode: number
  public isOperational: boolean

  constructor(message: string, statusCode: number) {
    super(message)
    this.statusCode = statusCode
    this.isOperational = true
    Error.captureStackTrace(this, this.constructor)
  }
}

// Global error handler
export const globalErrorHandler = (
  err: Error | AppError,
  req: Request,
  res: Response,
  next: NextFunction
): void => {
  if (err instanceof AppError) {
    res.status(err.statusCode).json({
      success: false,
      message: err.message
    })
    return
  }

  // Unexpected error
  console.error('Unexpected error:', err)
  res.status(500).json({
    success: false,
    message: 'Kuch gadbad ho gayi'
  })
}
```

---

## 4.8 Request Typing — Cheatsheet

```typescript
// Request<Params, ResBody, ReqBody, Query>

// Sirf params
Request<{ id: string }>

// Sirf body
Request<{}, {}, CreateUserDTO>

// Params + body
Request<{ id: string }, {}, UpdateUserDTO>

// Query params — GET /users?page=1&limit=10
Request<{}, {}, {}, { page: string; limit: string }>

// Sab
Request<{ id: string }, {}, UpdateUserDTO, { include: string }>
```

---

## ✅ Is Part Ke Baad Tumhe Aana Chahiye

- [ ] Express project TypeScript mein setup karna
- [ ] Controller mein Request/Response type karna
- [ ] Shared types ek file mein rakhna
- [ ] `req.user` extend karna
- [ ] Error middleware banana
