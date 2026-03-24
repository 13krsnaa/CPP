# 🎯 Quick Reference Card — TypeScript for MERN

> Coding ke waqt yahan dekho

---

## Type Syntax Cheatsheet

```typescript
// Primitives
let x: string = "hello"
let y: number = 42
let z: boolean = true
let n: null = null
let u: undefined = undefined

// Arrays
let arr1: string[] = []
let arr2: Array<number> = []

// Object
let obj: { name: string; age: number } = { name: "Rahul", age: 22 }

// Union
let id: string | number = "abc"

// Optional
interface User { name: string; age?: number }

// Readonly
interface Config { readonly apiKey: string }

// Function
const fn: (a: number, b: number) => number = (a, b) => a + b

// Generic
function identity<T>(value: T): T { return value }

// Async function
async function fetchUser(id: string): Promise<User> { ... }
```

---

## Common Utility Types

```typescript
Partial<User>          // sab optional
Required<User>         // sab required
Pick<User, 'id'|'name'> // sirf ye fields
Omit<User, 'password'> // ye field hata do
Readonly<User>         // change nahi kar sakte
Record<string, number> // { [key: string]: number }
ReturnType<typeof fn>  // function ka return type
```

---

## Express Types

```typescript
import { Request, Response, NextFunction } from 'express'

// Basic
(req: Request, res: Response) => void

// Typed params
Request<{ id: string }>

// Typed body
Request<{}, {}, CreateUserDTO>

// Typed query
Request<{}, {}, {}, { page: string }>

// Typed response
Response<ApiResponse<User>>

// Middleware
(req: Request, res: Response, next: NextFunction) => void
```

---

## React Types

```typescript
// Props
interface Props { children: React.ReactNode }

// useState
useState<User | null>(null)
useState<string[]>([])

// Events
React.ChangeEvent<HTMLInputElement>
React.FormEvent<HTMLFormElement>
React.MouseEvent<HTMLButtonElement>
React.KeyboardEvent<HTMLInputElement>

// Component
const Comp: React.FC<Props> = ({ children }) => ...

// Ref
const ref = useRef<HTMLInputElement>(null)

// Context
createContext<AuthContextType | undefined>(undefined)
```

---

## Mongoose Types

```typescript
import { Document, Types, Schema, model } from 'mongoose'

// Interface
interface IUser extends Document {
  name: string
}

// ObjectId
author: Types.ObjectId

// ObjectId to string
user._id.toString()

// Populate type
.populate<{ author: IUserDocument }>('author')

// Lean
.lean<IUser[]>()
```

---

## tsconfig.json Recommended

```json
{
  "compilerOptions": {
    "target": "ES2020",
    "module": "commonjs",
    "lib": ["ES2020"],
    "outDir": "./dist",
    "rootDir": "./src",
    "strict": true,
    "esModuleInterop": true,
    "skipLibCheck": true,
    "forceConsistentCasingInFileNames": true,
    "resolveJsonModule": true
  }
}
```

---

## Common @types Packages

```bash
npm install -D @types/node
npm install -D @types/express
npm install -D @types/cors
npm install -D @types/bcrypt
npm install -D @types/jsonwebtoken
npm install -D @types/multer
npm install -D @types/morgan
# React mein already included hain
```

---

## Error Quick Fix

| Error | Fix |
|-------|-----|
| `implicitly any` | Type likho |
| `possibly null` | `?.` ya null check |
| `not assignable` | Type match karo |
| `does not exist` | Interface update karo |
| `module not found` | `@types/` install karo |
| `_id not string` | `.toString()` lagao |
