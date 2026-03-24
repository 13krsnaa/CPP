# 07. Interfaces And Type Aliases

## Introduction

Jaise jaise project bada hota hai, object shapes ko bar bar likhna boring aur error-prone ho jata hai.
Yahan `interface` aur `type` help karte hain.

Ye dono reusable type definitions banane ke liye use hote hain.

---

## Interface

Interface mostly object structure define karne ke liye use hota hai.

```ts
interface User {
  id: number;
  name: string;
  email: string;
}
```

---

## Type Alias

Type alias sirf object tak limited nahi hai.
Ye unions, tuples, primitives aur complex combinations ke liye bhi use ho sakta hai.

```ts
type Status = "loading" | "success" | "error";
```

---

## Example

```ts
interface Product {
  id: number;
  title: string;
  price: number;
}

type ApiStatus = "idle" | "loading" | "success" | "error";

const product: Product = {
  id: 1,
  title: "Mouse",
  price: 799
};

let apiStatus: ApiStatus = "loading";

console.log(product.title);
console.log(apiStatus);
```

---

## Code Explanation

- `Product` ek reusable object contract hai
- `ApiStatus` fixed string values ka reusable type hai
- Code clean ho jata hai because repeated structure ek jagah define hota hai

---

## Interface Vs Type Alias

Use interface when:

- object shape define karna ho
- future me extend karna ho
- clean model-like structure chahiye

Use type alias when:

- union banana ho
- tuple banana ho
- combination type define karna ho

---

## Extending Interface

```ts
interface Person {
  name: string;
}

interface Employee extends Person {
  employeeId: number;
}
```

---

## Common Mistakes

- interface aur type ka exact difference samjhe bina random use karna
- reusable structures ko inline object typing me hi likhte rehna
- object property miss kar dena

---

## Practice Tasks

1. Ek `Student` interface banao jisme `name`, `rollNumber`, aur `isPresent` ho.
2. Ek `ResultStatus` type banao jo `"pass"` ya `"fail"` allow kare.
3. Ek `Teacher` interface banao jo `Person` jaisi base interface ko extend kare.

---

## Quick Summary

- interface reusable object contracts ke liye best hota hai
- type alias wider use-cases ke liye useful hota hai
- dono milkar code ko readable aur maintainable banate hain
