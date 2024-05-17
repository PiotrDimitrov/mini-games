# Sudoku Generator and Solver

This C++ project provides a comprehensive Sudoku generator and solver. It supports generating and solving different sizes of Sudoku puzzles, including the classic 9x9 and larger 16x16 grids. Users can solve puzzles directly in the console or input their own unsolved Sudoku puzzles for the program to solve.

## Features

- **Sudoku Generation**: Generates Sudoku puzzles of various sizes (e.g., 9x9, 16x16).
- **Sudoku Solver**: Solves Sudoku puzzles entered by the user.
- **Console Interaction**: Allows users to solve puzzles directly in the console.
- **Flexible Input**: Users can input their own unsolved Sudoku puzzles for the program to solve.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Getting Started

Follow these instructions to set up the project on your local machine for development and testing purposes.

### Prerequisites

Ensure you have the following software installed on your system:

- **C++ Compiler** (e.g., g++, clang++)
- **Make** (optional, for building projects with a Makefile)

### Installation

1. Clone the repository to your local machine:

    ```sh
    git clone PiotrDimitrovhttps://github.com/PiotrDimitrov/sudoku.git
    cd sudoku-generator-solver
    ```

2. Compile the project:

    ```sh
    g++ -o sudoku main.cpp SudokuGenerator.cpp SudokuSolver.cpp
    ```

*Note: Replace `main.cpp`, `SudokuGenerator.cpp`, and `SudokuSolver.cpp` with the actual source file names if different.*

### Usage

To use the Sudoku Generator and Solver:

1. Execute the compiled program:

    ```sh
    ./sudoku
    ```

2. Follow the on-screen prompts to:
    - Generate a new Sudoku puzzle.
    - Solve a Sudoku puzzle.
    - Input your own unsolved Sudoku puzzle for the program to solve.

## Examples

Here are some example operations you can perform with the Sudoku Generator and Solver:

1. **Generate a 9x9 Sudoku Puzzle**:

    ```sh
    Enter the size of the Sudoku puzzle (e.g., 9 for 9x9): 9
    Generated Sudoku Puzzle:
    5 3 _ | _ 7 _ | _ _ _
    6 _ _ | 1 9 5 | _ _ _
    _ 9 8 | _ _ _ | _ 6 _
    ------|-------|------
    8 _ _ | _ 6 _ | _ _ 3
    4 _ _ | 8 _ 3 | _ _ 1
    7 _ _ | _ 2 _ | _ _ 6
    ------|-------|------
    _ 6 _ | _ _ _ | 2 8 _
    _ _ _ | 4 1 9 | _ _ 5
    _ _ _ | _ 8 _ | _ 7 9
    ```

2. **Solve an Entered Sudoku Puzzle**:

    ```sh
    Enter the Sudoku puzzle to solve (use 0 for empty cells):
    530070000
    600195000
    098000060
    800060003
    400803001
    700020006
    060000280
    000419005
    000080079

    Solved Sudoku Puzzle:
    5 3 4 | 6 7 8 | 9 1 2
    6 7 2 | 1 9 5 | 3 4 8
    1 9 8 | 3 4 2 | 5 6 7
    ------|-------|------
    8 5 9 | 7 6 1 | 4 2 3
    4 2 6 | 8 5 3 | 7 9 1
    7 1 3 | 9 2 4 | 8 5 6
    ------|-------|------
    9 6 1 | 5 3 7 | 2 8 4
    2 8 7 | 4 1 9 | 6 3 5
    3 4 5 | 2 8 6 | 1 7 9
    ```

3. **Generate a 16x16 Sudoku Puzzle**:

    ```sh
    Enter the size of the Sudoku puzzle (e.g., 16 for 16x16): 16
    Generated 16x16 Sudoku Puzzle:
    A _ _ | _ B _ _ _ | _ C _ _ _ _ D
    _ _ 2 | _ _ _ 4 _ | _ _ _ _ _ _ _
    _ 3 _ | _ _ _ 8 _ | _ 9 _ _ _ _ _
    ------|-----------|-------------
    1 _ _ | 4 _ _ _ _ | _ _ 6 _ _ _ 7
    _ _ 5 | _ _ _ 7 _ | _ _ _ _ 9 _ _
    _ _ _ | _ _ _ _ _ | _ _ _ _ _ _ _
    ------|-----------|-------------
    _ _ _ | _ _ _ _ _ | _ _ _ _ _ _ _
    _ _ _ | _ 3 _ _ _ | _ _ _ _ _ _ _
    _ _ 8 | _ _ _ _ _ | _ _ _ 2 _ _ _
    ------|-----------|-------------
    _ 4 _ | _ _ _ 1 _ | _ 2 _ _ _ _ _
    _ _ _ | _ _ _ _ _ | _ _ _ _ _ _ _
    _ _ _ | 2 _ _ _ _ | _ _ _ 3 _ _ _
    ------|-----------|-------------
    _ 6 _ | _ _ _ 9 _ | _ _ _ _ _ _ _
    _ _ _ | _ _ _ _ _ | _ _ 5 _ _ _ _
    _ _ _ | _ _ 7 _ _ | _ _ _ _ _ _ _
    ```

## Contributing

Contributions are welcome! If you would like to contribute to the project, please follow these steps:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature/your-feature-name`.
3. Make your changes.
4. Commit your changes: `git commit -m 'Add some feature'`.
5. Push to the branch: `git push origin feature/your-feature-name`.
6. Open a pull request.

## Contact

If you have any questions or suggestions, feel free to contact me at:

- Email: piotr.dimitrov2019@gmail.com
- GitHub: [PiotrDimitrov](https://github.com/PiotrDimitrov)

Thank you for using the Sudoku Generator and Solver!