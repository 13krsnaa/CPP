# 📚 TypeScript Glossary — Simple Bhasha Mein

> Ye terms baar baar aayenge — ek baar samjho, phir bhoologe nahi

---

## A

| Term | Matlab |
|------|--------|
| **`any`** | "Mujhe type nahi pata" — TypeScript ki sabse buri chiz. Avoid karo. |
| **`as` (Type Assertion)** | "Main jaanta hoon ye is type ka hai" — `value as string` |
| **`async/await`** | Same as JS — sirf return type `Promise<T>` likhna hota hai |

## C

| Term | Matlab |
|------|--------|
| **Compiler** | TS code ko JS mein convert karta hai — `tsc` command |
| **`tsconfig.json`** | TypeScript ka config file — project root mein hota hai |

## E

| Term | Matlab |
|------|--------|
| **`enum`** | Fixed values ka set — `enum Status { Active, Inactive }` |
| **`extends`** | Ek interface doosre se inherit kare — `interface Admin extends User` |

## G

| Term | Matlab |
|------|--------|
| **Generic (`<T>`)** | "Koi bhi type chalega, but consistent rahega" — `Array<string>`, `Promise<User>` |

## I

| Term | Matlab |
|------|--------|
| **Interface** | Object ka shape define karna — `interface User { name: string }` |
| **Inference** | TypeScript khud type samajh le — `let x = 5` automatically `number` ho jata hai |

## N

| Term | Matlab |
|------|--------|
| **`never`** | Ye code kabhi nahi chalega — exhaustive checks mein use hota hai |
| **`null` / `undefined`** | Same as JS — but TS mein explicitly handle karna padta hai |

## O

| Term | Matlab |
|------|--------|
| **Optional (`?`)** | Field zaroori nahi hai — `name?: string` |

## T

| Term | Matlab |
|------|--------|
| **Type** | Interface jaisa hi — `type User = { name: string }` |
| **Type Alias** | Type ko naam dena — `type ID = string \| number` |
| **Type Guard** | Runtime pe type check karna — `if (typeof x === 'string')` |
| **`@types/`** | JS libraries ke liye type definitions — `@types/express`, `@types/node` |

## U

| Term | Matlab |
|------|--------|
| **Union Type (`\|`)** | "Ye ya wo" — `string \| number` |
| **`unknown`** | `any` se safe version — use karne se pehle type check zaroori |

## V

| Term | Matlab |
|------|--------|
| **`void`** | Function kuch return nahi karta — `function log(): void` |

---

## Interface vs Type — Bhai Kya Farak Hai?

```
┌─────────────────────────────────┬─────────────────────────────────┐
│           Interface             │              Type               │
├─────────────────────────────────┼─────────────────────────────────┤
│ Objects ke liye best            │ Everything ke liye kaam karta   │
│ Extend ho sakta hai             │ Union/Intersection kar sakte ho │
│ Declaration merging hoti hai    │ Primitive types bhi ban sakte   │
│                                 │                                 │
│ interface User {                │ type User = {                   │
│   name: string                  │   name: string                  │
│ }                               │ }                               │
│                                 │                                 │
│ // Objects ke liye use karo     │ type ID = string | number       │
└─────────────────────────────────┴─────────────────────────────────┘

Simple rule: Objects ke liye interface, baaki ke liye type
```

---

## Common Type Errors — Seedha Samjho

| Error | Matlab | Fix |
|-------|--------|-----|
| `Type 'string' is not assignable to type 'number'` | Wrong type de diya | Sahi type do |
| `Property 'x' does not exist on type 'Y'` | Object mein wo field nahi | Interface check karo |
| `Object is possibly 'undefined'` | Pehle check karo | `if (x)` ya `x?.property` |
| `Parameter 'x' implicitly has an 'any' type` | Type batao | `: string` likhna bhool gaye |
| `Cannot find module '@types/...'` | Type package nahi hai | `npm install -D @types/package` |

---

## Files — Kya Hota Hai Kisme?

| Extension | Kya Hai |
|-----------|---------|
| `.ts` | TypeScript file — Node/Express backend |
| `.tsx` | TypeScript + JSX — React components |
| `.d.ts` | Type declaration file — sirf types, koi code nahi |
| `tsconfig.json` | TS compiler config |
| `@types/` folder | Installed type packages |
