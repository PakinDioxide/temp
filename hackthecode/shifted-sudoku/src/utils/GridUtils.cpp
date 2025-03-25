#include "GridUtils.h"

void shiftRow(std::vector<std::vector<int>>& grid, int rowIndex, int shiftAmount) {
    int cols = grid[rowIndex].size();
    std::vector<int> tempRow(cols);
    
    for (int i = 0; i < cols; ++i) {
        tempRow[i] = grid[rowIndex][(i - shiftAmount + cols) % cols];
    }
    
    grid[rowIndex] = tempRow;
}

void shiftColumn(std::vector<std::vector<int>>& grid, int colIndex, int shiftAmount) {
    int rows = grid.size();
    std::vector<int> tempCol(rows);
    
    for (int i = 0; i < rows; ++i) {
        tempCol[i] = grid[(i - shiftAmount + rows) % rows][colIndex];
    }
    
    for (int i = 0; i < rows; ++i) {
        grid[i][colIndex] = tempCol[i];
    }
}