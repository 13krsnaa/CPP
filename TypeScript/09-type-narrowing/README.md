# 09. Type Narrowing

## Introduction

Jab koi value multiple types ki ho sakti hai, TypeScript tumhe bolta hai:
pehle check karo, phir safely use karo.

Is process ko `type narrowing` kehte hain.

---

## Why Narrowing Is Needed

```ts
function printId(id: string | number) {
  // id could be string or number
}
```

Yahan `id` par string-only methods directly use nahi kar sakte.
Pehle check karna hoga ki ye actually string hai ya number.

---

## Narrowing With `typeof`

```ts
function printId(id: string | number) {
  if (typeof id === "string") {
    console.log(id.toUpperCase());
  } else {
    console.log(id.toFixed(2));
  }
}
```

---

## Narrowing With `in`

```ts
type Admin = { name: string; permissions: string[] };
type Customer = { name: string; purchaseCount: number };

function printUserInfo(user: Admin | Customer) {
  if ("permissions" in user) {
    console.log(user.permissions);
  } else {
    console.log(user.purchaseCount);
  }
}
```

---

## Example With Discriminated Union

```ts
type Payment =
  | { method: "card"; cardNumber: string }
  | { method: "upi"; upiId: string };

function processPayment(payment: Payment) {
  if (payment.method === "card") {
    console.log(`Card: ${payment.cardNumber}`);
  } else {
    console.log(`UPI: ${payment.upiId}`);
  }
}
```

---

## Code Explanation

- `payment.method` ek shared property hai
- uski value dekhkar TypeScript samajh leta hai ki object kaunsa hai
- isliye correct properties safely access hoti hain

---

## Common Mistakes

- union type value ko direct use kar lena
- type check kiye bina specific property access karna
- narrowing ke baad bhi unnecessary type assertion use karna

---

## Practice Tasks

1. Ek function banao jo `string | number` input le aur type ke hisab se output kare.
2. Do object types banao aur `in` operator se unko narrow karo.
3. Ek discriminated union banao for `success` and `error` response shapes.

---

## Quick Summary

- type narrowing union types ke saath safe coding ka core concept hai
- `typeof`, `in`, aur discriminated unions common tools hain
- runtime checks TypeScript ko better understanding dete hain
