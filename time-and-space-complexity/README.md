# Time and Space Complexity

## Goal
To understand the efficiency of your code. In DSA, just "getting the right answer" is not enough; your solution must run within time (usually 1s) and memory limits.

## Core Concepts
- **Big O Notation**: Describing the worst-case upper bound of an algorithm.
- **Common Complexities**: $O(1)$, $O(\log N)$, $O(N)$, $O(N \log N)$, $O(N^2)$, $O(2^N)$.
- **Time Limits**: A typical competitive programming environment allows $\approx 10^8$ operations per second.
- **Space Complexity**: Measuring extra memory used (excluding input size).

## Common Mistakes
1. **Ignoring Constants**: Thinking $O(100N)$ is fundamentally different from $O(N)$ (it's not).
2. **Miscalculating Loops**: Assuming two separate loops are $O(N^2)$ when they are actually $O(N + N) = O(N)$.
3. **Ignoring Recursion Space**: Forgetting that each recursive call adds to the stack memory.

## Tasks
1. **Analysis 1**: Find the time complexity of a loop that iterates from 1 to $N$ with `i = i * 2`.
2. **Analysis 2**: Calculate the complexity of nested loops where the inner loop runs from `0` to `i`.
3. **The Limit**: If a problem has $N = 10^5$, which of these will likely fail: $O(N)$, $O(N \log N)$, $O(N^2)$?
4. **Space Profiler**: Write a function and determine its extra space complexity (ignoring the input).
