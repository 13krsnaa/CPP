# Strings

## Goal
To handle sequence of characters effectively. String manipulation is a huge part of interviews and competitive programming.

## Core Concepts
- **std::string**: The modern C++ string class (not to be confused with C-style `char*`).
- **Methods**: `size()`, `length()`, `push_back()`, `pop_back()`, `substr()`, and `find()`.
- **Concat**: Using `+` or `append()`.
- **String as Array**: Accessing characters via `s[i]`.

## Common Mistakes
1. **Expensive Copies**: Passing strings to functions by value instead of `const string&`.
2. **Subtraction Trap**: Using `s.length() - 1` when the string is empty (leading to an unsigned wrap-around error).
3. **Double Quotes vs Single**: Confusing `"string"` with `'c'` (character).

## Tasks
1. **Word Reverser**: Reverse each word in a given sentence while keeping the word order the same.
2. **Frequency Counter**: Count how many times each vowel appears in a string.
3. **Anagram Checker**: Given two strings, check if one is an anagram of the other.
4. **Compression**: Implement a basic string compression (e.g., `aaabbcc` -> `a3b2c2`).
