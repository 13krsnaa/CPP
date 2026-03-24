# 01. Why TypeScript And Setup

## Introduction

TypeScript JavaScript ka superset hai.
Iska matlab:

- JavaScript valid hai TypeScript me
- TypeScript extra type checking add karta hai
- Ye compile hota hai JavaScript me

Simple line me:

TypeScript tumhare code ko chalne se pehle check karta hai.

---

## Why It Matters For A JavaScript Developer

JavaScript me ye problem common hoti hai:

- galat type pass ho gaya
- object ka missing property use kar liya
- function unexpected value return kar raha hai
- error runtime me mila, bahut late

TypeScript in problems ko compile time par pakadne ki koshish karta hai.

---

## Core Idea

TypeScript ke 3 basic fayde:

1. Type safety
2. Better editor help
3. Large codebase me clarity

Ye especially tab useful hota hai jab:

- code bada ho
- team me kaam ho
- future me code maintain karna ho

---

## Basic Setup

```bash
npm init -y
npm install -D typescript
npx tsc --init
```

Ye commands kya karte hain:

- `npm init -y` project start karta hai
- `npm install -D typescript` TypeScript ko dev dependency banata hai
- `npx tsc --init` `tsconfig.json` banata hai

---

## Your First TypeScript Example

```ts
function add(a: number, b: number): number {
  return a + b;
}

console.log(add(10, 20));
// console.log(add("10", 20)); // TypeScript error
```

---

## Code Explanation

- `a: number` ka matlab `a` sirf number hona chahiye
- `b: number` ka matlab `b` bhi number hona chahiye
- `: number` after function means function number return karega
- Agar string pass karoge to TypeScript pehle hi error dikha dega

---

## JavaScript Vs TypeScript

JavaScript version:

```js
function add(a, b) {
  return a + b;
}
```

Isme tum kuch bhi pass kar sakte ho.
TypeScript version me tum clearly batate ho ki kis type ka data expected hai.

---

## Common Mistakes

- Sochna ki TypeScript alag language hai jo JavaScript se totally different hai
- Har jagah type manually likhna, even jab TypeScript khud infer kar sakta hai
- `tsconfig.json` ko ignore kar dena
- Error ko samjhe bina `any` use kar dena

---

## Practice Tasks

1. Ek `multiply` function banao jo do numbers le aur number return kare.
2. Same function me ek galat call likho jisme string pass ho aur error observe karo.
3. Apni language me likho: runtime error aur compile-time error me difference kya hai?

---

## Quick Summary

- TypeScript JavaScript ke upar type system add karta hai
- Ye code chalne se pehle bahut si galtiyan pakad sakta hai
- Setup simple hai: install TypeScript and create `tsconfig.json`
