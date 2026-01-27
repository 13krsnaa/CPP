# Recursion

## Goal
To master "thinking in sub-problems." Recursion is a fundamental concept for tree traversals, graph searches (DFS), and Dynamic Programming.

## Core Concepts
- **Base Case**: The condition that stops the recursion.
- **Recursive Step**: Calling the function with a smaller version of the same problem.
- **Call Stack**: How the computer remembers each function call's state.
- **Infinite Recursion**: Occurs when a base case is missing or never reached (leads to Stack Overflow).

## Common Mistakes
1. **Stack Overflow**: Forgetting the base case or passing too large a depth.
2. **Redundant Work**: Computing the same sub-problem multiple times (e.g., standard Fibonacci).
3. **Return Value Loss**: Forgetting to `return` the result of the recursive call.

## Tasks
1. **Factorial**: Implement the factorial function recursively.
2. **Fibonacci**: Write a recursive function to find the $n^{th}$ Fibonacci number.
3. **Sum of Digits**: Write a recursive function that sums the digits of a number.
4. **Reverse String**: Implement a recursive function to print a string in reverse.
