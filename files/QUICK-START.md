# ⚡ Quick Start — Pehle Ghante Mein TypeScript

> **Read Time**: 10 min | **Hands-on**: 1 hour  
> **Prerequisite**: Node.js aur npm aata ho

---

## Aaj Kya Banayenge?

1. ✅ TypeScript setup — Node project mein
2. ✅ Pehli `.ts` file
3. ✅ Ek chhota Express server TypeScript mein
4. ✅ Basic types ka use

---

## 🎯 Step 1: Samjho Kya Ho Raha Hai (5 min)

```
Tumhara JS code          TypeScript           Browser/Node
══════════════           ══════════           ════════════

server.js         ──X──► server.ts    ──tsc──► server.js
                         (types add)           (wahi JS)
                         
TypeScript ek layer hai JS ke upar.
Runtime pe sirf JS chalta hai.
TS sirf development mein help karta hai.
```

**Practical fayda**: VS Code mein galti hone se pehle hi red underline aa jaata hai.

---

## 🎯 Step 2: Setup (10 min)

```bash
# Naya folder banao
mkdir ts-practice && cd ts-practice
npm init -y

# TypeScript install karo
npm install -D typescript ts-node nodemon @types/node

# Config file banao
npx tsc --init
```

`tsconfig.json` mein ye changes karo:
```json
{
  "compilerOptions": {
    "target": "ES2020",
    "module": "commonjs",
    "outDir": "./dist",
    "rootDir": "./src",
    "strict": true,
    "esModuleInterop": true,
    "skipLibCheck": true
  },
  "include": ["src/**/*"],
  "exclude": ["node_modules"]
}
```

`package.json` mein scripts add karo:
```json
{
  "scripts": {
    "dev": "nodemon --exec ts-node src/index.ts",
    "build": "tsc",
    "start": "node dist/index.js"
  }
}
```

---

## 🎯 Step 3: Pehli TypeScript File (10 min)

`src/index.ts` banao:

```typescript
// ===== PART 1: Basic Types =====

// JS mein:
// let name = "Rahul"
// let age = 22

// TS mein — type batao:
let name: string = "Rahul"
let age: number = 22
let isStudent: boolean = true

// Array
let skills: string[] = ["JavaScript", "React", "Node"]

// Object
let user: { name: string; age: number } = {
  name: "Rahul",
  age: 22
}

// ===== PART 2: Interface =====

interface User {
  id: number
  name: string
  email: string
  age?: number   // ? matlab optional
}

const newUser: User = {
  id: 1,
  name: "Amit",
  email: "amit@gmail.com"
  // age optional hai, dena zaroori nahi
}

// ===== PART 3: Function Types =====

// JS mein:
// function greet(name) { return "Hello " + name }

// TS mein — parameter aur return type batao:
function greet(name: string): string {
  return `Hello ${name}`
}

// Arrow function
const add = (a: number, b: number): number => a + b

// Kuch return nahi karta
function logMessage(msg: string): void {
  console.log(msg)
}

// ===== PART 4: Chalo Run Karte Hain =====

console.log(greet("Rahul"))      // Hello Rahul
console.log(add(5, 3))           // 8
logMessage("TypeScript chal gaya! 🎉")
```

```bash
npm run dev
```

---

## 🎯 Step 4: Express Server TypeScript Mein (20 min)

```bash
npm install express
npm install -D @types/express
```

`src/server.ts` banao:

```typescript
import express, { Request, Response } from 'express'

const app = express()
app.use(express.json())

// ===== Types define karo =====

interface Product {
  id: number
  name: string
  price: number
  inStock: boolean
}

// Fake data
const products: Product[] = [
  { id: 1, name: "Laptop", price: 50000, inStock: true },
  { id: 2, name: "Mouse", price: 500, inStock: true },
  { id: 3, name: "Keyboard", price: 1200, inStock: false },
]

// ===== Routes =====

// GET all products
app.get('/products', (req: Request, res: Response) => {
  res.json(products)
})

// GET product by id
app.get('/products/:id', (req: Request, res: Response) => {
  const id = parseInt(req.params.id)  // string → number
  const product = products.find(p => p.id === id)
  
  if (!product) {
    return res.status(404).json({ message: "Product nahi mila" })
  }
  
  res.json(product)
})

// POST new product
app.post('/products', (req: Request, res: Response) => {
  const body: Omit<Product, 'id'> = req.body  // id auto-generate hoga
  
  const newProduct: Product = {
    id: products.length + 1,
    ...body
  }
  
  products.push(newProduct)
  res.status(201).json(newProduct)
})

app.listen(3000, () => {
  console.log('Server chal raha hai port 3000 pe 🚀')
})
```

```bash
npm run dev
```

Postman mein test karo:
- `GET http://localhost:3000/products`
- `GET http://localhost:3000/products/1`
- `POST http://localhost:3000/products` body ke saath

---

## ✅ Kya Seekha Aaj?

| Concept | Example |
|---------|---------|
| Basic types | `string`, `number`, `boolean` |
| Interface | Object ka shape define kiya |
| Optional field | `age?` |
| Function types | Parameters aur return type |
| Express typing | `Request`, `Response` import kiye |
| `Omit<T, K>` | Interface se ek field hataya |

---

## 🔴 Agar Kuch Kaam Na Kare

| Error | Fix |
|-------|-----|
| `Cannot find module 'express'` | `npm install express` |
| `Could not find declaration file for 'express'` | `npm install -D @types/express` |
| `strict mode` errors | `tsconfig.json` mein `"strict": false` (shuruaat mein) |
| `ts-node not found` | `npx ts-node src/index.ts` try karo |

---

## ▶️ Agle Steps

| Jab ready ho | Yahan jao |
|--------------|-----------|
| Types aur Interfaces deep dive | 02-TS-BASICS.md |
| Express API properly banana | 04-NODE-EXPRESS-TS.md |
| React mein TypeScript | 05-REACT-TS.md |
| MongoDB/Mongoose type karna | 06-MONGODB-MONGOOSE-TS.md |
