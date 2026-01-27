# Iterators and Range Loops

## Goal
To traverse STL containers in a clean and generic way. This is the modern C++ way to write code that works across different container types.

## Core Concepts
- **Iterators**: Objects that act like pointers to elements inside a container.
- **Range-Base For Loop**: The `for (auto &x : container)` syntax.
- **`begin()` and `end()`**: Iterators pointing to the first element and "one past the last" element.
- **Auto Keyword**: Let the compiler deduce the type for you.

## Common Mistakes
1. **End Dereference**: Accidentally trying to access `*container.end()` (which is illegal).
2. **Concurrent Modification**: Modifying a container (like `erase`) while iterating through it without updating the iterator.
3. **Copies in Loops**: Forgetting to use `auto &x` and using `auto x` instead, which creates a copy for every element.

## Tasks
1. **Vector Traversal**: Write three different ways to print a vector: index loop, iterator loop, and range-based for loop.
2. **Search and Erase**: Use an iterator to find the first occurrence of a number in a list and erase it.
3. **Distance**: Use `std::distance` to find how many elements are between two specific iterators.
4. **Map Iterator**: Use an iterator to print all key-value pairs in a `std::map`.
