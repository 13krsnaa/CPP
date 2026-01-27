# Map and Unordered Map

## Goal
To associate keys with values. Maps are the most versatile STL container, used for hashing, frequency counts, and memoization.

## Core Concepts
- **std::map**: Keys are sorted ($O(\log N)$).
- **std::unordered_map**: Keys are not sorted ($O(1)$ average).
- **Entry Structure**: Each element is a `std::pair<const Key, Value>`.
- **Indexing**: `m[key]` automatically creates an entry with a default value if the key doesn't exist.

## Common Mistakes
1. **Unintended Entry**: Using `m[key]` in a conditional (like `if(m[key] == 0)`) actually inserts that key into the map if it wasn't there. Use `m.count(key)` or `m.find(key)` instead.
2. **Complexity on Keys**: Using complex objects (like `vector` or `pair`) as keys in `unordered_map` without providing a custom hash function.
3. **Map vs Unordered**: Using `map` when order doesn't matter, missing out on potential $O(1)$ performance.

## Tasks
1. **Word Counter**: Read a paragraph and count the frequency of each word using a map.
2. **First Non-Repeating**: Find the first non-repeating character in a string using an `unordered_map`.
3. **Two-Sum**: (Classic) Given an array and a target, find the indices of two numbers that sum to target in $O(N)$ time using a map.
4. **Group Anagrams**: (Moderate) Given a list of strings, group them together if they are anagrams of each other.
