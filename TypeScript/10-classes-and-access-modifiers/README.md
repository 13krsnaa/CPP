# 10. Classes And Access Modifiers

## Introduction

TypeScript classes JavaScript classes ko stronger banati hain because tum fields, constructor parameters, aur access modifiers ko type ke saath define kar sakte ho.

---

## Basic Class Example

```ts
class User {
  name: string;

  constructor(name: string) {
    this.name = name;
  }
}
```

---

## Access Modifiers

TypeScript me common access modifiers:

- `public`
- `private`
- `protected`
- `readonly`

---

## Example

```ts
class BankAccount {
  public owner: string;
  private balance: number;
  readonly accountNumber: string;

  constructor(owner: string, balance: number, accountNumber: string) {
    this.owner = owner;
    this.balance = balance;
    this.accountNumber = accountNumber;
  }

  deposit(amount: number): void {
    this.balance += amount;
  }

  getBalance(): number {
    return this.balance;
  }
}

const account = new BankAccount("Aman", 5000, "AC123");
account.deposit(1000);
console.log(account.getBalance());
```

---

## Code Explanation

- `owner` public hai, so class ke bahar accessible hai
- `balance` private hai, direct access allowed nahi hai
- `accountNumber` readonly hai, once set hone ke baad change nahi karna chahiye
- `deposit` aur `getBalance` class methods hain

---

## Important Note

TypeScript ka `private` compile-time safety deta hai.
Agar runtime-level private behavior chahiye to JavaScript `#privateField` bhi alag concept hai.

---

## JavaScript Vs TypeScript

JavaScript class me tum structure aur expected types ko manually ya mentally track karte ho.
TypeScript class me wo contract code me visible hota hai.

---

## Common Mistakes

- sab kuch public rakh dena
- `readonly` ka purpose ignore karna
- class properties initialize na karna
- OOP sirf syntax ke liye use karna, clarity ke liye nahi

---

## Practice Tasks

1. Ek `Car` class banao jisme `brand` aur `year` ho.
2. Ek `StudentAccount` class banao jisme `private marks` ho aur unko read karne ke liye method ho.
3. Ek class banao jisme ek `readonly id` property ho.

---

## Quick Summary

- classes related data aur methods ko group karte hain
- access modifiers encapsulation aur control dete hain
- `readonly` useful protection deta hai
