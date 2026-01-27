# Priority Queue (Heap)

## Goal
To efficiently retrieve the maximum or minimum element in a shifting dataset. This is essential for Dijkstra's algorithm, Top K elements, and Huffman coding.

## Core Concepts
- **Max-Heap (Default)**: `std::priority_queue<int>` keeps the largest element at the top.
- **Min-Heap**: `std::priority_queue<int, vector<int>, greater<int>>` keeps the smallest element at the top.
- **Complexity**: $O(\log N)$ for `push` and `pop`, $O(1)$ for `top`.

## Common Mistakes
1. **Complexity Trip**: Thinking `top()` is $O(\log N)$ (it's $O(1)$).
2. **Wrong Container**: Forgetting the `greater<int>` syntax for min-heaps and using a regular queue instead.
3. **Internal Unordering**: Trying to iterate through a priority queue thinking it's sorted (only the `top` is guaranteed).

## Tasks
1. **K-th Smallest**: Use a max-heap to find the $K^{th}$ smallest element in an array.
2. **Merge K Sorted**: (Moderate) Use a priority queue to merge $K$ sorted arrays into one.
3. **Running Median**: (Challenge) Use two priority queues (min-heap and max-heap) to find the median of a stream of numbers.
4. **Task Scheduler**: Implement a simple task priority system where each task has a priority and the highest priority task is always processed first.
