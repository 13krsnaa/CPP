# 02. Basic Types

## Introduction

TypeScript me hum variable ke saath uska data type define kar sakte hain.

Sabse common basic types:

- `string`
- `number`
- `boolean`
- `null`
- `undefined`

---

## Why This Topic Matters

Basic types clear nahi honge to aage ke saare concepts weak ho jayenge.
TypeScript ki foundation hi ye hai ki tum bata sako data ka shape aur nature kya hai.

---

## Syntax

```ts
let userName: string = "Aman";
let age: number = 22;
let isLoggedIn: boolean = true;
let score: number = 99.5;
let emptyValue: null = null;
let notAssigned: undefined = undefined;
```

---

## Example

```ts
let courseName: string = "TypeScript Basics";
let lessonsCount: number = 12;
let isFree: boolean = false;

console.log(courseName);
console.log(lessonsCount);
console.log(isFree);
```

---

## Code Explanation

- `courseName` text store karta hai, isliye `string`
- `lessonsCount` number store karta hai, isliye `number`
- `isFree` true ya false hota hai, isliye `boolean`
- TypeScript ensure karta hai ki galat type accidentally assign na ho

---

## JavaScript Vs TypeScript

JavaScript me:

```js
let courseName = "TypeScript Basics";
let lessonsCount = 12;
let isFree = false;
```

Ye sahi hai, but explicit type declaration nahi hai.
TypeScript me readability aur safety dono improve hoti hain.

---

## Important Note

`number` me integer aur decimal dono aate hain.
JavaScript aur TypeScript dono me separate `int` aur `float` type nahi hota.

---

## Common Mistakes

- `string` aur `String` ko same samajhna
- `boolean` ke jagah `"true"` ya `"false"` string use karna
- `number` ke jagah `"25"` string store kar dena
- `null` aur `undefined` ka meaning mix kar dena

---

## Practice Tasks

1. `city` naam ka variable banao jiska type `string` ho.
2. `totalMarks` naam ka variable banao jiska type `number` ho.
3. `hasPassed` naam ka variable banao jiska type `boolean` ho.

---

## Quick Summary

- Basic types TypeScript ka starting point hain
- `string`, `number`, `boolean` sabse zyada use hote hain
- Sahi type choose karna code ko readable aur safe banata hai
