# 11. Utility Types

## Introduction

TypeScript kuch built-in helper types deta hai jo existing types ko transform karne me help karte hain.
Inhe utility types kehte hain.

Ye real projects me bahut useful hote hain, especially forms, APIs, updates, and derived models ke liye.

---

## Common Utility Types

- `Partial<T>`
- `Required<T>`
- `Pick<T, Keys>`
- `Omit<T, Keys>`
- `Record<Keys, Type>`

---

## Example Base Type

```ts
interface User {
  id: number;
  name: string;
  email: string;
  isAdmin: boolean;
}
```

---

## Example Usage

```ts
interface User {
  id: number;
  name: string;
  email: string;
  isAdmin: boolean;
}

type UserUpdate = Partial<User>;
type PublicUser = Pick<User, "id" | "name">;
type AdminConfig = Record<string, boolean>;

const updateData: UserUpdate = {
  name: "New Name"
};

const publicProfile: PublicUser = {
  id: 1,
  name: "Aman"
};

const permissions: AdminConfig = {
  canEdit: true,
  canDelete: false
};
```

---

## Code Explanation

- `Partial<User>` sab properties ko optional bana deta hai
- `Pick<User, "id" | "name">` sirf selected keys rakhta hai
- `Record<string, boolean>` ek object type banata hai jisme keys string aur values boolean hoti hain

---

## When They Help

- update payloads
- filtered response objects
- config maps
- form drafts
- reusable derived types

---

## Common Mistakes

- utility type use karna jab simple direct type enough ho
- `Partial` ko full validation replacement samajh lena
- `Pick` aur `Omit` ka wrong use karna

---

## Practice Tasks

1. Ek `Product` interface banao aur uska `Partial<Product>` update type create karo.
2. Ek `Pick` example banao jo sirf `id` aur `title` choose kare.
3. Ek `Record<string, number>` example banao for subject marks.

---

## Quick Summary

- utility types existing types ko reuse aur reshape karne me help karte hain
- ye real-world development me time bachate hain
- ye code ko DRY aur maintainable banate hain
