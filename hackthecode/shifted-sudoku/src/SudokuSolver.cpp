#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

class SudokuSolver {
public:
    SudokuSolver(const std::vector<std::vector<std::string>>& shiftedGrid, int shifts, char direction, int index);
    void reconstructGrid();
    bool solveSudoku();
    void printSolution();
    void clearGrid();

private:
    bool solve(int row, int col);
    bool isSafe(int row, int col, int num);

    std::vector<std::vector<std::string>> shiftedGrid;
    std::vector<std::vector<int>> originalGrid;
    int shifts;
    char direction;
    int index;
};

SudokuSolver::SudokuSolver(const std::vector<std::vector<std::string>>& shiftedGrid, int shifts, char direction, int index) {
    this->shiftedGrid = shiftedGrid;
    this->shifts = shifts;
    this->direction = direction;
    this->index = index;
    this->originalGrid = std::vector<std::vector<int>>(shiftedGrid.size(), std::vector<int>(shiftedGrid.size(), 0));
}

void SudokuSolver::reconstructGrid() {
    int N = shiftedGrid.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (shiftedGrid[i][j] != "X") {
                if (direction == 'R') {
                    originalGrid[i][(j + shifts) % N] = std::stoi(shiftedGrid[i][j]);
                } else if (direction == 'C') {
                    originalGrid[(i + shifts) % N][j] = std::stoi(shiftedGrid[i][j]);
                }
            }
        }
    }
}

bool SudokuSolver::solveSudoku() {
    return solve(0, 0);
}

bool SudokuSolver::solve(int row, int col) {
    int N = originalGrid.size();
    if (row == N) return true;
    if (col == N) return solve(row + 1, 0);
    if (originalGrid[row][col] != 0) return solve(row, col + 1);

    for (int num = 1; num <= N; ++num) {
        if (isSafe(row, col, num)) {
            originalGrid[row][col] = num;
            if (solve(row, col + 1)) return true;
            originalGrid[row][col] = 0;
        }
    }
    return false;
}

bool SudokuSolver::isSafe(int row, int col, int num) {
    int N = originalGrid.size();
    int sqrtN = std::sqrt(N);
    for (int x = 0; x < N; ++x) {
        if (originalGrid[row][x] == num || originalGrid[x][col] == num || 
            originalGrid[row - row % sqrtN + x / sqrtN][col - col % sqrtN + x % sqrtN] == num) {
            return false;
        }
    }
    return true;
}

void SudokuSolver::printSolution() {
    for (const auto& row : originalGrid) {
        for (const auto& num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

void SudokuSolver::clearGrid() {
    for (auto& row : originalGrid) {
        std::fill(row.begin(), row.end(), 0);
    }
}

int main() {
    int numCases;
    std::cin >> numCases;
    std::cin.ignore();

    for (int caseNum = 1; caseNum <= numCases; ++caseNum) {
        int N, S;
        std::cin >> N >> S;
        std::cin.ignore();

        std::vector<std::vector<std::string>> shiftedGrid(N, std::vector<std::string>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cin >> shiftedGrid[i][j];
            }
        }

        char direction;
        int index, shifts;
        std::cin >> direction >> index >> shifts;

        SudokuSolver solver(shiftedGrid, shifts, direction, index);
        solver.reconstructGrid();
        if (solver.solveSudoku()) {
            std::cout << "Case #" << caseNum << ": " << direction << " " << index << " " << shifts << std::endl;
            solver.printSolution();
        } else {
            std::cout << "No solution exists" << std::endl;
        }
        solver.clearGrid();
    }

    return 0;
}