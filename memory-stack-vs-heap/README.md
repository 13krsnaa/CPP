# Memory: Stack vs Heap

## Goal
To understand life cycles of variables and manual memory management. This is key for understanding recursion depth and dynamic structure allocation.

## Core Concepts
- **Stack Memory**: Fast, managed by the compiler, limited size. Used for local variables.
- **Heap Memory**: Slower, managed by the programmer, large size. Used for `new` and `malloc`.
- **Keywords**: `new` (allocate) and `delete` (deallocate).
- **Static vs Dynamic**: Knowing when to use which to avoid "Stack Overflow" for large arrays.

## Common Mistakes
1. **Memory Leaks**: Using `new` without a corresponding `delete`.
2. **Double Delete**: Attempting to free the same memory twice (causes crash).
3. **Large Local Arrays**: Allocating `int arr[1000000]` inside a function (often causes stack overflow; use `std::vector` or global/heap instead).

## Tasks
1. **Dynamic Integer**: Allocate an integer on the heap, modify it, print its address and value, and then delete it.
2. **Dynamic Array**: Ask the user for size $N$, allocate an array of size $N$ on the heap, fill it, and free the memory properly.
3. **Stack Overflow Demo**: (Caution) Create a recursive function without a base case and see how many calls it takes before the program crashes.
4. **Global Allocation**: Observe how declaring a large array globally (which goes into the data segment/heap-like area) avoids stack overflow compared to local declaration.
