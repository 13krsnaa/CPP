# 03. Inference, Any, Unknown, Never

## Introduction

TypeScript hamesha tumse type likhwana zaruri nahi samajhta.
Kai baar wo khud guess kar leta hai ki variable ka type kya hai.
Is process ko `type inference` kehte hain.

Isi topic me hum `any`, `unknown`, aur `never` bhi samjhenge.

---

## Type Inference

```ts
let language = "TypeScript";
let version = 5;
let isPopular = true;
```

Yahan TypeScript khud samajh leta hai:

- `language` is `string`
- `version` is `number`
- `isPopular` is `boolean`

Isliye har jagah explicit type likhna zaruri nahi hota.

---

## What Is `any`

`any` ka matlab:
TypeScript checking almost band kar do.

```ts
let data: any = "hello";
data = 100;
data = true;
```

Ye flexible hai, but dangerous bhi.
Jab tum `any` use karte ho, TypeScript tumhe protect kam karta hai.

---

## What Is `unknown`

`unknown` bhi flexible hai, but safer than `any`.
Tum value ko directly use nahi kar sakte jab tak uska type check na kar lo.

```ts
let response: unknown = "Hello";

if (typeof response === "string") {
  console.log(response.toUpperCase());
}
```

---

## What Is `never`

`never` usually un functions me aata hai jo kabhi normal value return hi nahi karte.

Example:

```ts
function throwError(message: string): never {
  throw new Error(message);
}
```

Ye function execution ko stop kar deta hai, isliye return type `never` hai.

---

## Example

```ts
let title = "Learning TS";
let apiData: unknown = '{"name":"Aman"}';

function fail(message: string): never {
  throw new Error(message);
}

if (typeof apiData === "string") {
  console.log(apiData.length);
} else {
  fail("Expected a string response");
}
```

---

## Code Explanation

- `title` me type infer hua as `string`
- `apiData` ka actual type unknown hai, isliye direct methods use nahi kar sakte
- `typeof apiData === "string"` ke baad TypeScript ko clarity milti hai
- `fail` function kabhi value return nahi karta, sirf error throw karta hai

---

## JavaScript Vs TypeScript

JavaScript me tum unknown value par seedha method chala dete ho aur error runtime me milta hai.
TypeScript kehta hai: pehle prove karo ki value kis type ki hai.

---

## Common Mistakes

- Error se bachne ke liye turant `any` use kar dena
- `unknown` ko `any` samajh lena
- `never` ko `void` ke saath confuse karna

Difference:

- `void` means function kuch useful return nahi karta
- `never` means function normal flow me return hi nahi karta

---

## Practice Tasks

1. Ek variable banao jisme type inference se `number` set ho.
2. Ek `unknown` variable banao aur usko safe type check ke baad use karo.
3. Ek function likho jo error throw kare aur uska return type `never` ho.

---

## Quick Summary

- Type inference TypeScript ka smart feature hai
- `any` se checking weak ho jati hai
- `unknown` safer option hai
- `never` un cases ke liye hota hai jahan function normal return nahi karta
