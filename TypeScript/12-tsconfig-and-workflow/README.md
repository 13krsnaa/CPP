# 12. tsconfig And Workflow

## Introduction

`tsconfig.json` TypeScript project ka control center hota hai.
Ye decide karta hai:

- compiler ka behavior kya hoga
- source files kahan hongi
- output kahan jayega
- strict rules on honge ya nahi

---

## Why This File Matters

Bahut beginners TypeScript install to kar lete hain, but `tsconfig.json` ko ignore kar dete hain.
Real projects me ye file bahut important hoti hai.

---

## Example `tsconfig.json`

```json
{
  "compilerOptions": {
    "target": "ES2020",
    "module": "CommonJS",
    "rootDir": "./src",
    "outDir": "./dist",
    "strict": true,
    "noImplicitAny": true,
    "esModuleInterop": true
  },
  "include": ["src"]
}
```

---

## Important Options

### `target`
JavaScript ka kaunsa version output me chahiye.

### `module`
Import/export system ka format.

### `rootDir`
Source code kaha hai.

### `outDir`
Compiled JavaScript kaha jayegi.

### `strict`
Strict type checking on karta hai.

### `noImplicitAny`
Jahan type clear na ho, wahan silently `any` allow na karo.

---

## Basic Workflow

```bash
npm install -D typescript
npx tsc --init
npx tsc
```

Agar watch mode chahiye:

```bash
npx tsc --watch
```

---

## Example Project Flow

```txt
project/
|-- src/
|   `-- index.ts
|-- dist/
|   `-- index.js
|-- package.json
`-- tsconfig.json
```

---

## JavaScript Developer Note

JavaScript project me configuration kam visible hoti hai.
TypeScript project me configuration quality directly affect karti hai.

Strict mode on rakhna generally best habit hai.

---

## Common Mistakes

- `strict` ko off rakhna without reason
- compiled files aur source files ko mix kar dena
- `rootDir` aur `outDir` clearly set na karna
- `tsconfig.json` ko copy-paste karna without understanding

---

## Practice Tasks

1. Ek basic `tsconfig.json` banao jisme `rootDir` `src` aur `outDir` `dist` ho.
2. `strict: true` aur `noImplicitAny: true` ka effect observe karo.
3. Ek chhota `src/index.ts` file socho aur likho ki compile hone ke baad output kahan aayega.

---

## Quick Summary

- `tsconfig.json` project-level TypeScript behavior control karta hai
- strict settings beginner ko better habits sikhati hain
- proper workflow samajhna syntax samajhne jitna hi important hai
