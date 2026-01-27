# Vector and Dynamic Arrays

## Goal
To use resizable arrays. Vectors are the "bread and butter" of STL; they handle memory management for you and are used for almost everything in DSA.

## Core Concepts
- **Dynamic Growth**: Vectors automatically resize when they run out of capacity.
- **Key Methods**: `push_back()`, `pop_back()`, `size()`, `clear()`, `resize()`.
- **Complexity**: $O(1)$ amortized for `push_back`, $O(1)$ for random access.
- **Initialization**: Different ways to declare (e.g., `vector<int> v(n, 0)`).

## Common Mistakes
1. **Inefficient Insertion**: Using `insert()` or `erase()` at the front/middle, which takes $O(N)$.
2. **Reserved Space**: Not using `reserve()` when you know the final size, causing multiple reallocations.
3. **Size vs Capacity**: Confusing how many elements are in the vector vs how much space is allocated.

## Tasks
1. **Dynamic List**: Read $N$ numbers into a vector and print them in reverse.
2. **Filter Even**: Write a function that takes a vector and returns a new vector containing only the even numbers.
3. **Unique Elements**: Remove consecutive duplicates from a vector without using `std::unique`.
4. **Vector 2D**: Create a 2D vector (vector of vectors) to represent a multiplication table.
