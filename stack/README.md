# Stack

## Goal
To master the Last-In-First-Out (LIFO) data structure. Stacks are essential for reversing data, balancing parentheses, and graph DFS.

## Core Concepts
- **LIFO Principle**: The last element added is the first one removed.
- **STL Stack**: `std::stack` operations: `push()`, `pop()`, `top()`, `empty()`, `size()`.
- **Internal Handling**: Stacks are usually built on top of `deque` or `vector`.

## Common Mistakes
1. **Popping Empty Stack**: Calling `pop()` or `top()` on an empty stack (causes a crash).
2. **Iterating**: Trying to iterate through a stack using a loop (stacks only allow access to the top).
3. **Complexity Confusion**: Forgetting that `top()` and `pop()` are $O(1)$.

## Tasks
1. **Reverser**: Read a string and use a stack to print it in reverse.
2. **Balanced Parentheses**: Write a function that checks if a string of `(` and `)` is balanced using a stack.
3. **Min Stack**: (Moderate) Implement a "Min Stack" that can return the minimum element in $O(1)$ time.
4. **Infix to Postfix**: (Challenge) Use a stack to convert a basic mathematical expression from infix to postfix notation.
