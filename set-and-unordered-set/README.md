# Set and Unordered Set

## Goal
To store unique elements and perform fast membership checks.

## Core Concepts
- **std::set**: Stores elements in sorted order. Operations are $O(\log N)$ (Balanced BST).
- **std::unordered_set**: Stores elements in no specific order. Operations are $O(1)$ average (Hash Table).
- **Methods**: `insert()`, `erase()`, `find()`, `count()`, `size()`.

## Common Mistakes
1. **Duplicate Expectation**: Forgeting that `set` automatically ignores duplicate inserts.
2. **Finding via Iterators**: Using `std::find(s.begin(), s.end(), x)` instead of the member function `s.find(x)` (member function is $O(\log N)$, standard is $O(N)$).
3. **Unordered Overhead**: Using `unordered_set` for small $N$ where a regular `set` might be faster due to constant factors.

## Tasks
1. **Unique Count**: Given an array with duplicates, return the count of unique elements using a set.
2. **Set Intersection**: Find common elements between two arrays using `unordered_set` for $O(N)$ efficiency.
3. **Ordered Print**: Read $N$ integers and print them in increasing order without using `std::sort`.
4. **Subset Checker**: Check if array B is a subset of array A using an `unordered_set`.
