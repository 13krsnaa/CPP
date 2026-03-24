# 📖 Part 2 — TypeScript Basics Deep Dive

> Tum JS jaante ho — main tumhe sirf differences bataunga

---

## 2.1 Types — JS vs TS Comparison

```typescript
// ════════════════════════════════════════
// JAVASCRIPT (kya hota tha)
// ════════════════════════════════════════

let x = 5
x = "hello"    // JS: no problem!
x = true       // JS: still no problem!

function multiply(a, b) {
  return a * b
}
multiply("5", 3)   // JS: "555" — bug!

// ════════════════════════════════════════
// TYPESCRIPT (ab kya hota hai)
// ════════════════════════════════════════

let x: number = 5
x = "hello"    // TS: ERROR! Type 'string' is not assignable to type 'number'

function multiply(a: number, b: number): number {
  return a * b
}
multiply("5", 3)   // TS: ERROR! phle hi pata chal gaya
```

---

## 2.2 Primitive Types

```typescript
// String
let firstName: string = "Rahul"
let lastName: string = 'Kumar'
let greeting: string = `Hello ${firstName}`   // template literal bhi kaam karta

// Number
let age: number = 22
let price: number = 999.99
let negative: number = -10

// Boolean
let isLoggedIn: boolean = true
let hasPermission: boolean = false

// null & undefined
let nothing: null = null
let notDefined: undefined = undefined

// any — AVOID KARO jab tak zaroorat na ho
let anything: any = "string"
anything = 5       // koi error nahi — TypeScript band ho gaya

// unknown — any se better version
let userInput: unknown = "hello"
// userInput.toUpperCase()  // ERROR — pehle check karo
if (typeof userInput === 'string') {
  userInput.toUpperCase()  // ab safe hai
}
```

---

## 2.3 Arrays & Objects

```typescript
// Arrays — 2 tarike
let names: string[] = ["Amit", "Raj", "Priya"]
let scores: Array<number> = [90, 85, 95]

// Mixed array
let mixed: (string | number)[] = ["hello", 42, "world"]

// Object — inline type
let person: { name: string; age: number; city: string } = {
  name: "Rahul",
  age: 22,
  city: "Delhi"
}

// Tuple — fixed length, fixed types
let coordinate: [number, number] = [28.6, 77.2]  // [lat, lng]
let entry: [string, number] = ["age", 22]
```

---

## 2.4 Interface — Object ka Blueprint

```typescript
// ===== Basic Interface =====

interface User {
  id: number
  name: string
  email: string
  age?: number      // optional
  readonly role: string  // sirf padhna, change nahi kar sakte
}

const user1: User = {
  id: 1,
  name: "Priya",
  email: "priya@gmail.com",
  role: "admin"
}

// user1.role = "user"  // ERROR — readonly hai

// ===== Interface Extend karna =====

interface Employee extends User {
  company: string
  salary: number
}

const emp: Employee = {
  id: 1,
  name: "Amit",
  email: "amit@company.com",
  role: "developer",
  company: "TechCorp",
  salary: 50000
}

// ===== Function Interface =====

interface LoginFn {
  (email: string, password: string): Promise<User>
}

// ===== Index Signature — dynamic keys =====

interface ErrorMessages {
  [key: string]: string
}

const errors: ErrorMessages = {
  email: "Email required hai",
  password: "Password 8 characters ka hona chahiye",
  name: "Naam required hai"
}
```

---

## 2.5 Type Alias — Reusable Types

```typescript
// ===== Basic Type Alias =====

type ID = string | number    // ye Union type hai

let userId: ID = 101
userId = "user_abc"  // dono valid hain

// ===== Object Type =====

type Product = {
  id: number
  name: string
  price: number
}

// ===== Union Types =====

type Status = "pending" | "approved" | "rejected"

function updateStatus(status: Status): void {
  console.log(`Status: ${status}`)
}

updateStatus("approved")    // ✅
// updateStatus("deleted")  // ❌ ERROR

// ===== Intersection Types =====

type Admin = {
  adminLevel: number
  permissions: string[]
}

type AdminUser = User & Admin   // User aur Admin dono ke fields

// ===== Practical Example =====

type ApiResponse<T> = {
  success: boolean
  data: T
  message?: string
}

type UserResponse = ApiResponse<User>
type ProductListResponse = ApiResponse<Product[]>
```

---

## 2.6 Generics — Ek Baar Likhao, Har Jagah Use Karo

```typescript
// ===== Problem without generics =====

function getFirstNumber(arr: number[]): number {
  return arr[0]
}

function getFirstString(arr: string[]): string {
  return arr[0]
}

// Same kaam, alag type — repeat ho raha hai!

// ===== Solution with generics =====

function getFirst<T>(arr: T[]): T {
  return arr[0]
}

getFirst<number>([1, 2, 3])          // returns number
getFirst<string>(["a", "b", "c"])    // returns string
getFirst([true, false])              // TS khud samjh gaya — boolean

// ===== Generic Interface =====

interface ApiResponse<T> {
  data: T
  statusCode: number
  message: string
}

// Use karo:
const userRes: ApiResponse<User> = {
  data: { id: 1, name: "Rahul", email: "r@r.com", role: "user" },
  statusCode: 200,
  message: "Success"
}

const productsRes: ApiResponse<Product[]> = {
  data: [{ id: 1, name: "Laptop", price: 50000 }],
  statusCode: 200,
  message: "Success"
}

// ===== Constrained Generic =====

// T ke paas id zaroori hona chahiye
function findById<T extends { id: number }>(items: T[], id: number): T | undefined {
  return items.find(item => item.id === id)
}
```

---

## 2.7 Enums — Fixed Values

```typescript
// ===== Numeric Enum =====

enum OrderStatus {
  Pending,    // 0
  Confirmed,  // 1
  Shipped,    // 2
  Delivered,  // 3
  Cancelled   // 4
}

let myOrder = OrderStatus.Pending
console.log(myOrder)  // 0

// ===== String Enum — production mein prefer karo =====

enum UserRole {
  Admin = "ADMIN",
  User = "USER",
  Moderator = "MODERATOR"
}

function checkPermission(role: UserRole): void {
  if (role === UserRole.Admin) {
    console.log("Full access")
  }
}

// ===== Alternative — Type literal (enum se better in many cases) =====

type OrderStatusType = "pending" | "confirmed" | "shipped" | "delivered" | "cancelled"
// Ye enum se zyada flexible hai
```

---

## 2.8 Utility Types — Ready-made Helpers

```typescript
// Ye TypeScript mein built-in hain — bahut useful

interface User {
  id: number
  name: string
  email: string
  password: string
  age: number
}

// ===== Partial — sab optional ho jata hai =====
// Useful: update/patch API mein
type UpdateUser = Partial<User>
// { id?: number; name?: string; email?: string; ... }

// ===== Required — sab required ho jata hai =====
type StrictUser = Required<User>

// ===== Pick — sirf kuch fields lo =====
// Useful: public API response mein password hide karna
type PublicUser = Pick<User, 'id' | 'name' | 'email'>
// { id: number; name: string; email: string }

// ===== Omit — kuch fields hata do =====
type CreateUser = Omit<User, 'id'>  // id auto-generate hogi
// { name: string; email: string; password: string; age: number }

// ===== Readonly — koi change nahi kar sakta =====
type ImmutableUser = Readonly<User>

// ===== Record — object type =====
type UserPermissions = Record<UserRole, string[]>

// ===== Practical Example =====

// POST /users — id nahi chahiye
function createUser(userData: Omit<User, 'id'>): User {
  return { id: Math.random(), ...userData }
}

// PATCH /users/:id — sirf kuch fields update karo
function updateUser(id: number, updates: Partial<Omit<User, 'id'>>): User {
  // update logic...
  return {} as User
}
```

---

## ✅ Checklist — Ye Aata Hai Kya?

- [ ] `string`, `number`, `boolean` type likh sakta hoon
- [ ] Interface bana sakta hoon
- [ ] Optional field `?` use kar sakta hoon
- [ ] Union type `|` use kar sakta hoon
- [ ] Generic `<T>` ka concept samajh aa gaya
- [ ] `Partial`, `Pick`, `Omit` pata hai kab use karna

---

## ▶️ Agle Step

| Ready Ho Jao | Yahan Jao |
|--------------|-----------|
| Advanced types | 03-ADVANCED-TYPES.md |
| Express API banana | 04-NODE-EXPRESS-TS.md |
| React typing | 05-REACT-TS.md |
