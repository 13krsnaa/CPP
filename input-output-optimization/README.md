# Input/Output Optimization

## Goal
To avoid "Time Limit Exceeded" (TLE) in problems where the input size is large ($> 10^5$ items). Sometimes the bottleneck isn't your algorithm, but the slow default I/O in C++.

## Core Concepts
- **The Sync**: `ios::sync_with_stdio(0);` decouples C++ streams from C streams for speed.
- **The Tie**: `cin.tie(0);` prevents `cout` from flushing before `cin` is called.
- **The Flush**: `endl` forces a buffer flush which is slow; use `\n` instead.
- **Fast I/O**: Use these commands at the very beginning of your `main()`.

## Common Mistakes
1. **Mixing I/O**: Using `scanf`/`printf` alongside `cin`/`cout` after calling `sync_with_stdio(0)` (causes undefined behavior).
2. **Over-flushing**: Using `endl` inside a loop that runs $10^5$ times.
3. **Ignoring the Bottleneck**: Spending hours optimizing an $O(N \log N)$ algorithm when the real issue was slow I/O.

## Tasks
1. **Speed Test**: Write two programs that print 1 million numbers. One using `endl` and one using `\n`. Measure the time difference.
2. **The Fast Template**: Create a boilerplate C++ template that includes the I/O optimization lines.
3. **Large Input**: Write a program that reads $10^6$ integers and calculates their sum. Use `cin.tie(0)` to ensure it runs efficiently.
4. **Buffer Insight**: Explain in a comment why `std::endl` is slower than `\n`.
