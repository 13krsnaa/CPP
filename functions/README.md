# Functions

## Goal
To write modular, reusable, and clean code. Functions allow you to break down a large problem into smaller sub-problems, which is critical for complex DSA implementations.

## Core Concepts
- **Declaration vs Definition**: Informing the compiler about a function before calling it.
- **Parameters**: Passing inputs to functions.
- **Return Types**: How a function gives back a result (or `void` if it doesn't).
- **Scope**: Variables declared inside a function are not accessible outside.

## Common Mistakes
1. **Missing Return**: Forgetting to return a value in a non-void function.
2. **Re-declaring Globals**: Creating a local variable with the same name as a global one (shadowing).
3. **Return Type Mismatch**: Attempting to return an `int` when the function is declared to return a `string`.
4. **Infinite Calls**: Accidentally calling a function within itself without a termination condition (leads to recursion issues).

## Tasks
1. **Power Function**: Write a custom function `calculatePower(base, exponent)` that returns $base^{exponent}$ without using `<cmath>`.
2. **Palindrome Checker**: Create a function that takes a string and returns `true` if it's a palindrome.
3. **GCD Function**: Implement a function to find the Greatest Common Divisor of two numbers using the Euclidean algorithm.
4. **Function Overloading**: Create two functions named `area`—one calculating the area of a circle and another for a rectangle.
