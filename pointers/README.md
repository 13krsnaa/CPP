# Pointers

## Goal
To understand how C++ interacts with memory directly. Pointers are essential for building dynamic data structures like Linked Lists and Trees.

## Core Concepts
- **Address-of Operator (`&`)**: Getting the memory location of a variable.
- **Dereferencing Operator (`*`)**: Accessing the value stored at a pointer's address.
- **Null Pointers**: Initializing pointers to `nullptr` to avoid "wild" pointers.
- **Pointer Arithmetic**: Moving pointers through memory (e.g., `ptr++`).

## Common Mistakes
1. **Dangling Pointers**: Accessing memory after it has been freed or the variable has gone out of scope.
2. **Wild Pointers**: Using a pointer that was never initialized.
3. **Memory Leaks**: Losing the address of heap-allocated memory without deleting it.
4. **Incorrect De-referencing**: Confusing `*ptr` (the value) with `ptr` (the address).

## Tasks
1. **Address Swap**: Take two integers and swap their values using only pointers.
2. **Pointer Array**: Declare an array and use a pointer to iterate through and print all elements.
3. **Double Pointer**: Create a pointer to a pointer and use it to modify an integer value.
4. **Const Pointers**: Write examples of:
   - A pointer to a constant integer.
   - A constant pointer to an integer.
   - Explain the difference in comments.
