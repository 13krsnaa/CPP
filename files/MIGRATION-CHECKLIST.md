# ✅ Migration Checklist — JS Project ko TS Mein Convert Karo

> Existing MERN project mein TypeScript add karne ka step-by-step guide

---

## ✅ Phase 1: Setup (Pehla Din)

### Backend Setup

| Kaam | Status |
|------|--------|
| `npm install -D typescript ts-node nodemon @types/node` | ⬜ |
| `npm install -D @types/express @types/cors @types/bcrypt @types/jsonwebtoken` | ⬜ |
| `npx tsc --init` karke tsconfig.json banaya | ⬜ |
| `package.json` mein scripts update kiye (`dev`, `build`, `start`) | ⬜ |
| `.js` extension `.ts` mein rename kiya | ⬜ |
| `tsconfig.json` mein `"strict": false` rakha (pehle) | ⬜ |

### Frontend Setup

| Kaam | Status |
|------|--------|
| `npm install -D typescript @types/react @types/react-dom` | ⬜ |
| `tsconfig.json` add kiya | ⬜ |
| `.jsx` files ko `.tsx` mein rename kiya | ⬜ |
| `.js` files ko `.ts` mein rename kiya | ⬜ |

---

## ✅ Phase 2: Types Create Karo (Doosra Din)

| Kaam | Status |
|------|--------|
| `src/types/index.ts` file banai | ⬜ |
| Sabse common interfaces define kiye (User, Product, etc.) | ⬜ |
| API response type define kiya (`ApiResponse<T>`) | ⬜ |
| `req.user` ke liye Express extend kiya | ⬜ |

---

## ✅ Phase 3: Backend Convert Karo

### Models

| Kaam | Status |
|------|--------|
| Har model ke liye Interface banaya | ⬜ |
| Interface + Document type banaya | ⬜ |
| Schema mein generic type add kiya | ⬜ |

### Controllers

| Kaam | Status |
|------|--------|
| `Request` aur `Response` import kiye | ⬜ |
| Har function ka return type `Promise<void>` | ⬜ |
| `req.params`, `req.body`, `req.query` type kiye | ⬜ |
| Error handling mein `error instanceof Error` check | ⬜ |

### Middleware

| Kaam | Status |
|------|--------|
| Auth middleware properly typed | ⬜ |
| Error middleware properly typed | ⬜ |

---

## ✅ Phase 4: Frontend Convert Karo

### Components

| Kaam | Status |
|------|--------|
| Har component ka Props interface banaya | ⬜ |
| `children: React.ReactNode` add kiya jahan zaroorat | ⬜ |

### Hooks

| Kaam | Status |
|------|--------|
| `useState` mein generic type add kiya | ⬜ |
| Event handlers mein proper type | ⬜ |
| Custom hooks properly typed | ⬜ |

### API Calls

| Kaam | Status |
|------|--------|
| Fetch/Axios response types define kiye | ⬜ |
| Loading aur error states typed | ⬜ |

---

## ✅ Phase 5: Strict Mode Enable Karo (Last Mein)

```json
// tsconfig.json
{
  "compilerOptions": {
    "strict": true    // sab errors fix hone ke baad enable karo
  }
}
```

| Kaam | Status |
|------|--------|
| `strict: true` enable kiya | ⬜ |
| Saare null check errors fix kiye | ⬜ |
| Saare implicit any errors fix kiye | ⬜ |
| Build successfully complete hoti hai | ⬜ |
| Tests pass ho rahe hain | ⬜ |

---

## 📝 Migration Tips

```
1. Ek file at a time migrate karo — poora project ek saath mat karo
2. `strict: false` se shuru karo — dhire dhire strict mode enable karo  
3. `any` type use karo jab stuck ho — baad mein fix karna
4. Types folder pehle banao — baki sab baad mein
5. Models se shuru karo — Controller types models pe depend karte hain
```

---

## Common Migration Errors

| Error | Fix |
|-------|-----|
| `require()` error | `import/export` use karo |
| Module not found | `@types/` install karo |
| `process.env.X` undefined | `.env` file check karo ya `!` assertion |
| Mongoose `_id` string nahi | `.toString()` use karo |
| `res.json()` type error | Return type specify karo |
