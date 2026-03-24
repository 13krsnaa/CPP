# 06. Unions, Literal Types, Enums

## Introduction

Kabhi kabhi ek variable sirf ek type ka nahi hota.
Kabhi wo `string` ya `number` dono ho sakta hai.
Kabhi allowed values bahut specific hoti hain.

In sab cases me unions, literal types, aur enums help karte hain.

---

## Union Types

Union type ka matlab:
Ek value multiple possible types me se kisi ek type ki ho sakti hai.

```ts
let orderId: string | number;

orderId = "ORD-101";
orderId = 101;
```

---

## Literal Types

Literal type me allowed values fixed hoti hain.

```ts
let status: "pending" | "success" | "failed";
```

Is variable me sirf in teen values me se koi ek hi aa sakti hai.

---

## Enums

Enum named constants ka group hota hai.

```ts
enum Role {
  Admin = "ADMIN",
  User = "USER",
  Guest = "GUEST"
}
```

---

## Example

```ts
type PaymentStatus = "pending" | "paid" | "cancelled";

enum UserRole {
  Admin = "ADMIN",
  Editor = "EDITOR",
  Viewer = "VIEWER"
}

let paymentStatus: PaymentStatus = "paid";
let currentRole: UserRole = UserRole.Admin;

console.log(paymentStatus);
console.log(currentRole);
```

---

## Code Explanation

- `PaymentStatus` ek literal union type hai
- `paymentStatus` me random string nahi aa sakti
- `UserRole` enum reusable constants provide karta hai
- `currentRole` ko enum members me se hi value milegi

---

## JavaScript Vs TypeScript

JavaScript me tum `"paid"` ki jagah `"payd"` bhi likh do to typo runtime tak chhup sakta hai.
TypeScript literal types aur enums se aise typos kam hote hain.

---

## Common Mistakes

- unions ke saath narrowing na karna
- enum aur literal type ko bina samjhe interchangeably use karna
- allowed values ko too broad rakh dena

Tip:

- simple fixed strings ke liye literal types enough hote hain
- named reusable constant set ke liye enums use kar sakte ho

---

## Practice Tasks

1. Ek variable banao jo `string | number` accept kare.
2. Ek `theme` type banao jo sirf `"light"` ya `"dark"` allow kare.
3. Ek enum banao jisme `Low`, `Medium`, `High` priority values ho.

---

## Quick Summary

- unions flexibility dete hain
- literal types exact allowed values define karte hain
- enums named constant groups provide karte hain
