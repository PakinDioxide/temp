#ifndef GRIDUTILS_H
#define GRIDUTILS_H

#include <vector>

void shiftRow(std::vector<std::vector<int>>& grid, int rowIndex, int shiftAmount);
void shiftColumn(std::vector<std::vector<int>>& grid, int colIndex, int shiftAmount);

#endif // GRIDUTILS_H