# Conditionals

## Goal
To control the flow of execution based on data. Many DSA problems require handling multiple cases, such as boundaries, negative numbers, or specific constraints.

## Core Concepts
- **If-Else Hierarchy**: Using `if`, `else if`, and `else` for mutually exclusive conditions.
- **Switch Case**: An efficient alternative for multiple constant-value checks.
- **Ternary Operator**: Concise syntax `(condition ? true_val : false_val)` for simple assignments.
- **Logical Operators**: Combining conditions using `&&` (AND), `||` (OR), and `!` (NOT).

## Common Mistakes
1. **Assignment vs Equality**: Using `=` (assignment) instead of `==` (comparison).
2. **Missing Braces**: Assuming multiple lines fall under an `if` without using `{}`.
3. **Inefficient Ordering**: Not checking the most likely or most "expensive" conditions first in a long `else if` chain.
4. **Redundant Logic**: Checking `if (x > 0)` and then `if (x <= 0)` instead of using `else`.

## Tasks
1. **Quadrant Finder**: Take `x` and `y` coordinates as input and determine which quadrant the point lies in.
2. **Leap Year Checker**: Write a program to check if a given year is a leap year (must be divisible by 4, but not 100 unless divisible by 400).
3. **Score Card**: Implement a program that takes a score (0-100) and prints a grade (A, B, C, D, F) using a `switch` statement or `if-else` ladder.
4. **Smallest of Three**: Write a function that takes three integers and returns the smallest one using the ternary operator.
