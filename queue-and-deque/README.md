# Queue and Deque

## Goal
To understand Linear and Double-Ended queues. Queues are the core of Breadth-First Search (BFS) and sliding window algorithms.

## Core Concepts
- **Queue (FIFO)**: First-In-First-Out. Element added at the back and removed from the front.
- **Deque (Double-Ended Queue)**: Elements can be added or removed from both ends.
- **Methods**:
  - `std::queue`: `push()`, `pop()`, `front()`, `back()`.
  - `std::deque`: `push_front()`, `push_back()`, `pop_front()`, `pop_back()`, `at()`.

## Common Mistakes
1. **Queue Access**: Trying to access the middle of a `std::queue` (not allowed; use `deque` for that).
2. **Back/Front Confusion**: Forgetting that `pop()` in a queue removes from the `front`.
3. **Empty Checks**: Forgetting `q.empty()` before calling `front()`.

## Tasks
1. **First K Reversal**: Reverse the first $K$ elements of a queue.
2. **Sliding Window Max**: (Moderate) Use a `deque` to find the maximum element in every sliding window of size $K$ in an array.
3. **Generate Binary**: Use a queue to generate binary numbers from 1 to $N$.
4. **Circular Queue**: Implement a circular queue using an array.
