# 🔴 Part 8 — Common TypeScript Errors & Fixes

> Ye errors sab beginners ko milte hain — aur sab ke fixes yahan hain

---

## Error 1: "Type 'X' is not assignable to type 'Y'"

```typescript
// ❌ Problem
let age: number = "22"   // Error!

// ✅ Fix
let age: number = 22
// ya
let age: string = "22"

// ❌ Real scenario
interface User {
  role: 'admin' | 'user'
}
const role = "admin"  // TypeScript isko 'string' samjhta hai
const user: User = { role }  // Error!

// ✅ Fix
const role = "admin" as const   // ab 'admin' literal type hai
// ya
const role: 'admin' | 'user' = "admin"
```

---

## Error 2: "Object is possibly 'null' or 'undefined'"

```typescript
// ❌ Problem
const user = users.find(u => u.id === id)
console.log(user.name)   // Error! user undefined ho sakta hai

// ✅ Fix 1: Check karo
if (user) {
  console.log(user.name)
}

// ✅ Fix 2: Optional chaining
console.log(user?.name)

// ✅ Fix 3: Non-null assertion (sirf tab jab sure ho)
console.log(user!.name)   // ! matlab "main guarantee deta hoon ye null nahi"

// ✅ Fix 4: Default value
const name = user?.name ?? "Unknown"
```

---

## Error 3: "Parameter 'x' implicitly has an 'any' type"

```typescript
// ❌ Problem
function greet(name) {    // Error! name ka type pata nahi
  return `Hello ${name}`
}

// ❌ Express mein
app.get('/users', (req, res) => {   // Error!
  res.json({})
})

// ✅ Fix
function greet(name: string): string {
  return `Hello ${name}`
}

// ✅ Express fix
import { Request, Response } from 'express'
app.get('/users', (req: Request, res: Response) => {
  res.json({})
})
```

---

## Error 4: "Property 'X' does not exist on type 'Y'"

```typescript
// ❌ Problem 1: req.user
app.get('/profile', (req: Request, res: Response) => {
  console.log(req.user)   // Error! Request mein user nahi hota default mein
})

// ✅ Fix: Express Request extend karo
// src/types/index.ts mein:
declare global {
  namespace Express {
    interface Request {
      user?: { id: string; email: string; role: string }
    }
  }
}

// ❌ Problem 2: Response ka body
const user = await User.findById(id)
console.log(user.name)   // Error! findById null return kar sakta hai

// ✅ Fix
const user = await User.findById(id)
if (!user) throw new Error('User not found')
console.log(user.name)   // Ab safe hai
```

---

## Error 5: "Cannot find module '@types/...'"

```bash
# ❌ Error: Could not find a declaration file for module 'express'

# ✅ Fix: Types package install karo
npm install -D @types/express
npm install -D @types/node
npm install -D @types/cors
npm install -D @types/bcrypt
npm install -D @types/jsonwebtoken

# Check karo package mein types hain ya nahi:
# node_modules/package/package.json mein "types" ya "typings" field dekho
```

---

## Error 6: Mongoose + TypeScript Issues

```typescript
// ❌ Problem: _id ka type
const user = await User.findById(id)
const userId: string = user._id   // Error! _id ObjectId type hai

// ✅ Fix
const userId: string = user._id.toString()

// ❌ Problem: Populate ka type
const post = await Post.findById(id).populate('author')
console.log(post.author.name)   // Error! author ObjectId type hai

// ✅ Fix
const post = await Post.findById(id)
  .populate<{ author: IUserDocument }>('author')
console.log(post.author.name)   // Ab kaam karega

// ❌ Problem: lean() ka type
const users = await User.find().lean()
// users type: Document[] nahi, plain objects hain

// ✅ Fix
const users = await User.find().lean<IUser[]>()
```

---

## Error 7: Async/Await Issues

```typescript
// ❌ Problem: unhandled promise
const user = await User.findById(id)
// Agar error aaye toh? Crash ho jayega

// ✅ Fix: try-catch
try {
  const user = await User.findById(id)
  if (!user) {
    return res.status(404).json({ message: 'Not found' })
  }
  res.json(user)
} catch (error) {
  // ❌ Galat: error.message directly nahi
  // res.status(500).json({ message: error.message })

  // ✅ Sahi: Error type check karo
  res.status(500).json({
    message: error instanceof Error ? error.message : 'Unknown error'
  })
}
```

---

## Error 8: React Specific Errors

```tsx
// ❌ Problem: Event type galat
const handleChange = (e) => {   // Error!
  setValue(e.target.value)
}

// ✅ Fix
const handleChange = (e: React.ChangeEvent<HTMLInputElement>) => {
  setValue(e.target.value)
}

// ❌ Problem: useState initial value
const [user, setUser] = useState(null)   // type 'null' hi rahega
setUser({ id: 1, name: 'Rahul' })   // Error!

// ✅ Fix: Generic do
const [user, setUser] = useState<User | null>(null)
setUser({ id: 1, name: 'Rahul', email: 'r@r.com', role: 'user', createdAt: new Date() })

// ❌ Problem: Children prop missing
interface Props { title: string }
const Card = ({ title, children }: Props) => ...   // Error!

// ✅ Fix
interface Props {
  title: string
  children: React.ReactNode
}
```

---

## Error 9: Strict Mode Issues

```typescript
// tsconfig.json mein "strict": true hone se ye errors aate hain

// ❌ strictNullChecks
function getName(user: User | null): string {
  return user.name   // Error! user null ho sakta hai
}

// ✅ Fix
function getName(user: User | null): string {
  return user?.name ?? 'Unknown'
}

// ❌ strictPropertyInitialization (Classes mein)
class UserService {
  private db: Database   // Error! initialized nahi hai
}

// ✅ Fix
class UserService {
  private db: Database

  constructor(db: Database) {
    this.db = db
  }
  // ya
  private db!: Database   // "! " matlab "main initialize karunga baad mein"
}
```

---

## Quick Fixes Table

| Error | 1-Line Fix |
|-------|-----------|
| `implicitly any` | Type explicitly likho |
| `possibly null` | `?.` ya `if (x)` use karo |
| `not assignable` | Types match karo ya `as` use karo |
| `does not exist` | Interface mein field add karo |
| `module not found` | `npm install -D @types/package` |
| `ObjectId not string` | `.toString()` call karo |
| `Promise<void> error` | `async function(): Promise<void>` likho |

---

## TypeScript Mein Debugging Tips

```typescript
// 1. Type check karo VS Code mein — hover karke dekho
const x = someFunction()   // Hover karke dekho x ka type kya hai

// 2. Temporary any use karo debug ke liye
const result: any = complexFunction()
console.log(result)   // pehle dekho kya aata hai, phir type do

// 3. Type assertion se shuru karo
const user = apiResponse as User
// Phir dhire dhire properly type karo

// 4. Console log ke saath type log karo
console.log(typeof value, value)
```
