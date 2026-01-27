# Two-Dimensional Arrays

## Goal
To represent tabular data and grids. In DSA, 2D arrays are frequently used for Matrix problems, Image processing, and Graph adjacency matrices.

## Core Concepts
- **Row-Major Order**: How 2D arrays are actually stored in 1D memory.
- **Nested Iteration**: Using two loops (outer for rows, inner for columns).
- **Initialization**: Specifying dimensions like `matrix[Rows][Cols]`.

## Common Mistakes
1. **Index Swap**: Confusing `matrix[row][col]` with `matrix[col][row]`.
2. **Hardcoded Limits**: Mixing up row and column counts in non-square matrices.
3. **Efficiency**: Iterating through columns first (Column-Major) which is slower due to cache misses.

## Tasks
1. **Matrix Sum**: Write a program to add two $N \times M$ matrices.
2. **Transpose**: Convert a given matrix into its transpose (swap rows and columns).
3. **Row/Col Sum**: Given a matrix, print the sum of each individual row and each individual column.
4. **Diagonal Sum**: Find the sum of the primary and secondary diagonals of a square matrix.
