# 08. Generics

## Introduction

Generics ka purpose hai reusable code likhna bina type information lose kiye.

Simple words me:

Generic function ya type ek placeholder type ke saath kaam karta hai.
Baad me actual type decide hota hai.

---

## Why Generics Matter

Without generics, tumhe ya to:

- alag alag functions likhne padte
- ya `any` use karna padta

Generics dono problems ko solve karte hain.

---

## Basic Syntax

```ts
function identity<T>(value: T): T {
  return value;
}
```

Yahan `T` ek type placeholder hai.

---

## Example

```ts
function firstItem<T>(items: T[]): T | undefined {
  return items[0];
}

const firstNumber = firstItem<number>([10, 20, 30]);
const firstName = firstItem<string>(["Aman", "Sara"]);

console.log(firstNumber);
console.log(firstName);
```

---

## Code Explanation

- `T[]` means array of some type `T`
- function jo bhi array type receive karega, usi type ka first item return karega
- `number[]` dene par return type `number | undefined`
- `string[]` dene par return type `string | undefined`

---

## Generic Type Example

```ts
type ApiResponse<T> = {
  data: T;
  success: boolean;
};
```

Ye bahut common real-world pattern hai.

---

## JavaScript Vs TypeScript

JavaScript me reusable function likhna easy hai, but returned data ka exact type preserve karna easy nahi hota.
TypeScript generics ke through type ko carry forward karta hai.

---

## Common Mistakes

- generic ko unnecessary difficult bana dena
- har function me generic use karne ki koshish karna
- `T` ka purpose samjhe bina sirf syntax yaad karna

Remember:

Generic tab useful hai jab input aur output type logically connected ho.

---

## Practice Tasks

1. Ek generic `getLastItem<T>` function banao jo array ka last element return kare.
2. Ek generic type banao `Box<T>` jisme ek property `value` ho.
3. Ek generic function banao jo input value ko array ke andar wrap karke return kare.

---

## Quick Summary

- generics reusable aur type-safe code ke liye hote hain
- `any` ki jagah better solution dete hain
- input aur output ke type relation ko preserve karte hain
