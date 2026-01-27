# References and Pass by Reference

## Goal
To pass data between functions efficiently. Using references prevents the creation of unnecessary copies of large objects (like vectors or strings), which is crucial for performance in DSA.

## Core Concepts
- **Reference Variable (`&`)**: An alias or second name for an existing variable.
- **Pass by Value**: Passing a copy; changes inside the function don't affect the original.
- **Pass by Reference**: Passing the original variable; changes affect the caller.
- **Const References**: Passing by reference to save memory, but with a `const` guard to prevent modification.

## Common Mistakes
1. **Returning Local References**: Attempting to return a reference to a variable that lives on the function's stack (it disappears after return).
2. **Confusing with Pointers**: References cannot be null and cannot be "reseated" (re-pointed) like pointers.
3. **Missing `const`**: Not using `const &` for large objects that you don't intend to modify.

## Tasks
1. **The Incrementor**: Write a function that increments an integer passed by reference.
2. **Vector Summer**: Write a function that takes a `const std::vector<int>&` and returns the sum of its elements (ensure no copy is made).
3. **Swap by Reference**: Implement the `swap` logic using references instead of pointers.
4. **Modification**: Write a function that takes a string by reference and converts it to uppercase.
