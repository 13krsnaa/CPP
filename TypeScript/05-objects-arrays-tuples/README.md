# 05. Objects, Arrays, Tuples

## Introduction

Real applications me data mostly objects aur arrays ke form me hota hai.
TypeScript ka ek major strength ye hai ki wo in data structures ko clearly type kar sakta hai.

---

## Objects

```ts
let user: { name: string; age: number; isAdmin: boolean } = {
  name: "Aman",
  age: 22,
  isAdmin: false
};
```

Yahan object ki shape clearly define hai.

---

## Arrays

```ts
let skills: string[] = ["HTML", "CSS", "TypeScript"];
let marks: number[] = [78, 85, 92];
```

`string[]` means array ke sab elements string hone chahiye.

---

## Tuples

Tuple fixed-length array hota hai jisme har position ka type known hota hai.

```ts
let userRecord: [string, number] = ["Aman", 22];
```

Yahan:

- first value `string`
- second value `number`

---

## Example

```ts
let product: {
  id: number;
  name: string;
  tags: string[];
  rating: [number, string];
} = {
  id: 101,
  name: "Keyboard",
  tags: ["electronics", "office"],
  rating: [5, "Excellent"]
};

console.log(product.name);
console.log(product.tags[0]);
console.log(product.rating[1]);
```

---

## Code Explanation

- `id` must be `number`
- `name` must be `string`
- `tags` is array of strings
- `rating` is tuple where first value number and second value string

Isse structure readable aur predictable ban jata hai.

---

## JavaScript Vs TypeScript

JavaScript me object ka exact shape document karna mushkil hota hai.
TypeScript me tum object ke andar ka contract seedha code me likh dete ho.

---

## Common Mistakes

- array type ko object type ke saath mix kar dena
- tuple me wrong order ka value rakh dena
- object ki required property miss kar dena

---

## Practice Tasks

1. Ek `student` object banao jisme `name`, `className`, aur `rollNumber` ho.
2. Ek `fruits` array banao jo sirf strings accept kare.
3. Ek tuple banao jo `[string, boolean]` format follow kare.

---

## Quick Summary

- objects shape define karte hain
- arrays same type ke multiple values rakhte hain
- tuples fixed structure ke liye useful hote hain
