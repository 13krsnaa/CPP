# Basics and Input/Output

## Goal
To master the standard way of interacting with a C++ program. In DSA, you must know how to read various data types and how to output them with precision, as most problems involve automated testing against specific input formats.

## Core Concepts
- **Standard I/O**: Understanding `cin` for input and `cout` for output.
- **Data Types**: Choosing between `int`, `long long`, `float`, `double`, and `char` based on constraints (e.g., $10^9$ fits in `int`, $10^{18}$ requires `long long`).
- **Formatting**: Using `fixed` and `setprecision` from `<iomanip>` for floating-point values.
- **Buffers**: Understanding how `cin` skips whitespace and how to use `getline()` for full lines.

## Common Mistakes
1. **Overflow**: Using `int` for a calculation that exceeds $2 \cdot 10^9$.
2. **Buffer Issues**: Mixing `cin >> x` and `getline(cin, s)` without handling the trailing newline (`cin.ignore()`).
3. **Semicolon Errors**: Forgetting the semicolon at the end of statements.
4. **Namespace**: Not using `std::` or `using namespace std;` properly.

## Tasks
1. **The Calculator**: Write a program that takes two integers and an operator (`+`, `-`, `*`, `/`) and performs the calculation. Ensure you handle division by zero.
2. **Precision Matters**: Write a program that reads a double and prints it with exactly 4 decimal places.
3. **Data Type Explorer**: Create a program that reads a `char`, an `int`, and a `double`, and prints their sizes in bytes using the `sizeof` operator.
4. **Line Reader**: Implement a program that reads a full sentence (including spaces) and prints the number of words in it.
