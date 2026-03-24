# 04. Functions

## Introduction

Functions TypeScript ka bahut important part hain, kyunki real projects me almost har logic function ke through likha jata hai.

TypeScript functions me tum:

- parameter types define kar sakte ho
- return type define kar sakte ho
- optional parameters use kar sakte ho
- default values de sakte ho

---

## Basic Syntax

```ts
function greet(name: string): string {
  return `Hello, ${name}`;
}
```

---

## Example

```ts
function createInvoice(
  customerName: string,
  amount: number,
  paid: boolean = false
): string {
  const paymentStatus = paid ? "Paid" : "Pending";
  return `${customerName} - Rs.${amount} - ${paymentStatus}`;
}

console.log(createInvoice("Aman", 1200));
console.log(createInvoice("Sara", 2500, true));
```

---

## Code Explanation

- `customerName: string` means first argument text hoga
- `amount: number` means second argument number hoga
- `paid: boolean = false` means third argument optional feel hota hai because default value di gayi hai
- `: string` batata hai function string return karega

---

## Optional Parameters

```ts
function showMessage(message: string, prefix?: string): string {
  return prefix ? `${prefix}: ${message}` : message;
}
```

Yahan `prefix?` optional hai.

---

## JavaScript Vs TypeScript

JavaScript me function kuch bhi receive kar leta hai.
TypeScript me tum clear contract likhte ho:

- kya input aayega
- kya output jayega

Ye contract future bugs kam karta hai.

---

## Common Mistakes

- return type ko ignore kar dena jab function complex ho
- optional parameter ko required parameter se pehle rakh dena
- function ko wrong argument order ke saath call karna

---

## Practice Tasks

1. Ek `subtract` function banao jo do numbers le aur difference return kare.
2. Ek `welcomeUser` function banao jisme second parameter optional ho.
3. Ek `calculateDiscount` function banao jisme default discount value ho.

---

## Quick Summary

- TypeScript functions me input aur output dono clear hote hain
- optional aur default parameters function ko flexible banate hain
- typed functions large projects me bahut help karte hain
