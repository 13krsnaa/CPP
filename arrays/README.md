# Arrays

## Goal
To store and manipulate collections of data in contiguous memory. Arrays are the most basic data structure and form the foundation for others like Lists and Heaps.

## Core Concepts
- **Index-based Access**: Elements are accessed in $O(1)$ time using `arr[i]`.
- **Initialization**: Static arrays have a fixed size at compile-time.
- **Traversal**: Using loops to visit every element.
- **Memory Layout**: Understanding how elements are stored side-by-side.

## Common Mistakes
1. **Out-of-Bounds**: Accessing `arr[N]` when the size is `N` (indices are 0 to $N-1$).
2. **Size Confusion**: Passing an array to a function often decays it to a pointer, losing size information.
3. **Initialization Bias**: Assuming local arrays are initialized to zero (they contain garbage values).

## Tasks
1. **Peak Finder**: Find the maximum and minimum elements in an array.
2. **Array Reverser**: Write a function that reverses an array in-place without using another array.
3. **Rotate Array**: Write a program to rotate an array to the right by $K$ steps.
4. **Subarray Sum**: Implement a function that returns the sum of elements from index $L$ to $R$.
