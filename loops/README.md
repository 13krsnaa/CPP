# Loops

## Goal
To automate repetitive tasks efficiently. Loops are the primary tool for traversing data structures and repeating logic.

## Core Concepts
- **For Loop**: Best for iterating when the range is known (e.g., $0$ to $N$).
- **While Loop**: Best when the condition depends on dynamic changes (e.g., until a target is reached).
- **Do-While**: Ensures the block runs at least once.
- **Control Statements**: Using `break` to exit early and `continue` to skip the current iteration.

## Common Mistakes
1. **Infinite Loops**: Forgetting to update the loop variable (e.g., `i++`).
2. **Off-by-One Errors**: Starting at 1 instead of 0, or using `<` instead of `<=` incorrectly.
3. **Modification during Iteration**: Changing the loop variable inside the block in a way that causes skipping or repeats.
4. **Nested Complexity**: Not realizing that a loop inside a loop leads to $O(N^2)$ complexity.

## Tasks
1. **Multiplication Table**: Print the multiplication table of a number `N` up to 10.
2. **Factorial Helper**: Implement a `while` loop to calculate the factorial of a number `N`.
3. **Prime Checker**: Write a program that checks if a number is prime by iterating from 2 to $\sqrt{N}$.
4. **Digit Sum**: Take an integer as input and use a loop to find the sum of its digits.
