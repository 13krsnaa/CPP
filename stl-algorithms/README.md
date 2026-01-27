# STL Algorithms

## Goal
To avoid "reinventing the wheel." C++ provides a massive library of high-performance algorithms that solve common problems in one line.

## Core Concepts
- **Headers**: Most live in `<algorithm>` or `<numeric>`.
- **Sorting**: `std::sort(begin, end)`.
- **Searching**: `std::binary_search`, `std::lower_bound`, `std::upper_bound`.
- **Modifying**: `std::reverse`, `std::fill`, `std::iota`.
- **Min/Max**: `std::min_element`, `std::max_element`.

## Common Mistakes
1. **Sorted Requirement**: Using `binary_search` or `lower_bound` on an unsorted container (leads to wrong results).
2. **End Iterator**: Passing a pointer to the value itself instead of the end iterator.
3. **Complexity Ignorance**: Not knowing that `std::sort` is $O(N \log N)$ while `std::stable_sort` might have different overhead.

## Tasks
1. **The Sorter**: Read $N$ strings and sort them by length (not alphabetically).
2. **Bound Finder**: In a sorted array, find the first and last position of a target number using `lower_bound` and `upper_bound`.
3. **Accumulator**: Use `std::accumulate` from `<numeric>` to find the sum and product of all elements in a vector.
4. **Permutations**: Use `std::next_permutation` to print all possible arrangements of the string "abc".
