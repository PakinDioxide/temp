# Shifted Sudoku Project

## Overview
The Shifted Sudoku project aims to reconstruct the original Sudoku grid from a shifted version and provide a solution to the puzzle. The project includes a Sudoku solver that can handle various configurations of shifted grids and restore them to their original state.

## Project Structure
```
shifted-sudoku
├── src
│   ├── main.cpp
│   ├── SudokuSolver.cpp
│   ├── SudokuSolver.h
│   └── utils
│       ├── GridUtils.cpp
│       └── GridUtils.h
├── CMakeLists.txt
└── README.md
```

## Building the Project
To build the project, you need to have CMake installed. Follow these steps:

1. Clone the repository or download the project files.
2. Open a terminal and navigate to the project directory.
3. Create a build directory:
   ```
   mkdir build
   cd build
   ```
4. Run CMake to configure the project:
   ```
   cmake ..
   ```
5. Compile the project:
   ```
   make
   ```

## Running the Project
After building the project, you can run the application using the following command:
```
./shifted-sudoku
```

## Example Input/Output
### Input
A shifted Sudoku grid can be provided as input, for example:
```
5 3 . | . 7 . | . . .
6 . . | 1 9 5 | . . .
. 9 8 | . . . | . 6 .
---------------------
8 . . | . 6 . | . . 3
4 . . | 8 . 3 | . . 1
7 . . | . 2 . | . . 6
---------------------
. 6 . | . . . | 2 8 .
. . . | 4 1 9 | . . 5
. . . | . 8 . | . 7 9
```

### Output
The program will output the reconstructed and solved Sudoku grid.

## Contributing
Contributions are welcome! If you have suggestions for improvements or additional features, please feel free to submit a pull request.

## License
This project is licensed under the MIT License. See the LICENSE file for details.