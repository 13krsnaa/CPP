# Const and Static Keywords

## Goal
To write safer and more efficient code. `const` ensures data integrity, while `static` manages persistence across function calls or classes.

## Core Concepts
- **const**: A promise that a value won't change after initialization.
- **static (in functions)**: A variable that retains its value between function calls.
- **static (in classes)**: A variable or function shared by all instances of the class.
- **const references**: Preventing modification while avoiding copies.

## Common Mistakes
1. **Static Pollution**: Overusing static variables instead of passing parameters, making the code hard to test.
2. **Non-const parameters**: Not using `const` for parameters that aren't supposed to change.
3. **Static Initialization**: Forgetting that static members of a class must be initialized outside the class.

## Tasks
1. **The Counter**: Write a function `callCount()` that uses a `static` variable to print how many times it has been called.
2. **Const Pointer**: Write a code snippet demonstrateing the difference between a pointer to a constant and a constant pointer.
3. **Shared Variable**: Create a class `User` with a `static` member that keeps track of how many `User` objects have been created.
4. **Read-Only**: Create a function that takes a large vector by `const` reference and prints its elements, ensuring no data can be modified.
