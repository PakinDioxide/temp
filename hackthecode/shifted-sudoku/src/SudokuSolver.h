#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <vector>
#include <string>

class SudokuSolver {
public:
    void reconstructGrid(const std::vector<std::vector<std::string>>& shiftedGrid, int shifts, char direction, int index);
    bool solveSudoku();
    void printSolution();

private:
    std::vector<std::vector<int>> grid;
    bool isValid(int row, int col, int num);
    bool findEmptyLocation(int &row, int &col);
};

#endif // SUDOKUSOLVER_H