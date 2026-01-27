# Pair and Custom Structures

## Goal
To group related data of different types. `std::pair` is perfect for simple coordinate-like data, while `struct` allows for custom complex objects.

## Core Concepts
- **std::pair**: Combining two values (e.g., `pair<int, string>`).
- **Accessing Pairs**: Using `.first` and `.second`.
- **Structs**: Defining a custom "blueprint" (e.g., `struct Student { string name; int age; };`).
- **Making Pairs**: Using `make_pair(a, b)` or `{a, b}`.

## Common Mistakes
1. **Default Comparison**: Not realizing that `pair` compares `.first` then `.second` by default.
2. **Memory Overhead**: Using a `struct` when two separate vectors or a `pair` would be simpler.
3. **Initialization**: Forgetting to initialize fields in a `struct`.

## Tasks
1. **Point Distance**: Create a `struct Point` with `x` and `y`. Write a function to calculate the distance between two points.
2. **Student Record**: Create a `struct` for a student. Store 3 students in a vector and find the one with the highest marks.
3. **Sort Pairs**: Create a vector of `pair<int, int>` and sort them. Observe the default sorting behavior.
4. **Coordinates**: Take a list of coordinates as input and store them as pairs in a vector.
