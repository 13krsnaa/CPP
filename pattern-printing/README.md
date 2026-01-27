# Pattern Printing

## Goal
To master nested loops and coordinate-based thinking. This is a common exercise to build the logic required for 2D array traversal and matrix manipulation.

## Core Concepts
- **Inner vs Outer**: The outer loop usually handles rows, and the inner loop handles columns.
- **Dependency**: Inner loop limits or values often depend on the outer loop iterator `i`.
- **Symmetry**: Recognizing patterns like mirroring or inverted triangles.

## Common Mistakes
1. **Line Breaks**: Forgetting to use `cout << endl;` after the inner loop finishes.
2. **Indexing Confusion**: Using the same variable for both inner and outer loops.
3. **Inverted Logic**: Struggling to reverse the count for inverted patterns (e.g., $N$ to 1).

## Tasks
1. **Right-Angled Triangle**: Print a triangle of `*` with `N` rows where row `i` has `i` stars.
2. **Pyramid**: Print a centered pyramid of `*`.
3. **Number Square**: Print a $N \times N$ square where each cell contains the value of its row index.
4. **Hollow Rectangle**: Print a hollow rectangle of stars with height `H` and width `W`.
