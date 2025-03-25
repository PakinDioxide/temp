#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,no-stack-protector,inline-small-functions,inline,unsafe-math-optimizations,omit-frame-pointer,inline-functions-called-once")
#include <bits/stdc++.h>
#pragma GCC target("avx2,fma,popcnt,lzcnt,bmi,bmi2,sse4.2,tune=native")
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

class SudokuBoard {
private:
    vector<vector<int>> grid;
    int N, sqrtN;
    // Bitmasks for solver optimization
    vector<int> rowMask, colMask, boxMask;

public:
    SudokuBoard(int size) : N(size), sqrtN(static_cast<int>(sqrt(size))), 
                            grid(size, vector<int>(size, 0)),
                            rowMask(size, 0), colMask(size, 0), boxMask(size, 0) {
        if (sqrtN * sqrtN != size) {
            cerr << "Assuming N is a perfect square for simplicity\n";
            sqrtN = 0; // Fallback, though we expect perfect squares
        }
    }

    void parseBoard(const vector<string>& lines) {
        for (int i = 0; i < N; i++) {
            istringstream iss(lines[i]);
            string cell;
            for (int j = 0; j < N; j++) {
                iss >> cell;
                grid[i][j] = (cell == "X") ? 0 : stoi(cell);
                if (grid[i][j] > 0) {
                    int num = grid[i][j] - 1; // 0-based for bitmask
                    rowMask[i] |= (1 << num);
                    colMask[j] |= (1 << num);
                    if (sqrtN > 0) {
                        int box = (i / sqrtN) * sqrtN + (j / sqrtN);
                        boxMask[box] |= (1 << num);
                    }
                }
            }
        }
    }

    const vector<vector<int>>& getGrid() const { return grid; }
    vector<vector<int>>& getGridMutable() { return grid; }
    void setGrid(const vector<vector<int>>& g) {
        grid = g;
        // Recompute masks
        rowMask.assign(N, 0);
        colMask.assign(N, 0);
        boxMask.assign(N, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] > 0) {
                    int num = grid[i][j] - 1;
                    rowMask[i] |= (1 << num);
                    colMask[j] |= (1 << num);
                    if (sqrtN > 0) {
                        int box = (i / sqrtN) * sqrtN + (j / sqrtN);
                        boxMask[box] |= (1 << num);
                    }
                }
            }
        }
    }

    void shiftRowLeft(int row, int shift) {
        auto& r = grid[row];
        rotate(r.begin(), r.begin() + shift, r.end());
    }

    void shiftColumnUp(int col, int shift) {
        vector<int> temp(N);
        for (int i = 0; i < N; i++) {
            temp[(i - shift + N) % N] = grid[i][col];
        }
        for (int i = 0; i < N; i++) {
            grid[i][col] = temp[i];
        }
    }

    bool isValid() const {
        if (sqrtN == 0) return true;
        for (int box = 0; box < N; box++) {
            vector<bool> seen(N + 1, false);
            int boxRow = (box / sqrtN) * sqrtN;
            int boxCol = (box % sqrtN) * sqrtN;
            for (int i = boxRow; i < boxRow + sqrtN; i++) {
                for (int j = boxCol; j < boxCol + sqrtN; j++) {
                    int num = grid[i][j];
                    if (num > 0) {
                        if (seen[num]) return false;
                        seen[num] = true;
                    }
                }
            }
        }
        return true;
    }

    bool solve() {
        int row, col;
        if (!findEmpty(row, col)) return true;
        int box = (row / sqrtN) * sqrtN + (col / sqrtN);
        for (int num = 0; num < N; num++) {
            if (!(rowMask[row] & (1 << num)) && 
                !(colMask[col] & (1 << num)) && 
                !(boxMask[box] & (1 << num))) {
                grid[row][col] = num + 1;
                rowMask[row] |= (1 << num);
                colMask[col] |= (1 << num);
                boxMask[box] |= (1 << num);
                if (solve()) return true;
                grid[row][col] = 0;
                rowMask[row] &= ~(1 << num);
                colMask[col] &= ~(1 << num);
                boxMask[box] &= ~(1 << num);
            }
        }
        return false;
    }

private:
    bool findEmpty(int& row, int& col) const {
        for (row = 0; row < N; row++) {
            for (col = 0; col < N; col++) {
                if (grid[row][col] == 0) return true;
            }
        }
        return false;
    }
};

struct ShiftInfo {
    char type; // 'R' or 'C'
    int index, amount;
};

// Identify subgrids with duplicates
vector<int> getProblematicSubgrids(const SudokuBoard& board) {
    vector<int> problematic;
    int N = board.getGrid().size();
    int sqrtN = static_cast<int>(sqrt(N));
    for (int box = 0; box < N; box++) {
        vector<bool> seen(N + 1, false);
        int boxRow = (box / sqrtN) * sqrtN;
        int boxCol = (box % sqrtN) * sqrtN;
        for (int i = boxRow; i < boxRow + sqrtN; i++) {
            for (int j = boxCol; j < boxCol + sqrtN; j++) {
                int num = board.getGrid()[i][j];
                if (num > 0) {
                    if (seen[num]) {
                        problematic.push_back(box);
                        break;
                    }
                    seen[num] = true;
                }
            }
            if (!problematic.empty() && problematic.back() == box) break;
        }
    }
    return problematic;
}

// Backtracking to find valid shift combinations
bool tryCombinations(SudokuBoard& board, vector<ShiftInfo>& shifts, int S,
                     const vector<pair<char, int>>& candidates, int start,
                     vector<ShiftInfo>& bestShifts, SudokuBoard& solvedBoard) {
    if (shifts.size() == S) {
        if (board.isValid()) {
            SudokuBoard testBoard(board.getGrid().size());
            testBoard.setGrid(board.getGrid());
            if (testBoard.solve()) {
                solvedBoard = testBoard;
                bestShifts = shifts;
                return true;
            }
        }
        return false;
    }

    int N = board.getGrid().size();
    for (int idx = start; idx < candidates.size(); idx++) {
        char type = candidates[idx].first;
        int line = candidates[idx].second;
        for (int shift = 1; shift < N; shift++) {
            if (type == 'R') {
                vector<int> original = board.getGrid()[line];
                board.shiftRowLeft(line, shift);
                shifts.push_back({'R', line, shift});
                if (tryCombinations(board, shifts, S, candidates, idx + 1, bestShifts, solvedBoard)) {
                    return true;
                }
                shifts.pop_back();
                board.getGridMutable()[line] = original;
            } else { // 'C'
                vector<int> original(N);
                for (int i = 0; i < N; i++) {
                    original[i] = board.getGrid()[i][line];
                }
                board.shiftColumnUp(line, shift);
                shifts.push_back({'C', line, shift});
                if (tryCombinations(board, shifts, S, candidates, idx + 1, bestShifts, solvedBoard)) {
                    return true;
                }
                shifts.pop_back();
                for (int i = 0; i < N; i++) {
                    board.getGridMutable()[i][line] = original[i];
                }
            }
        }
    }
    return false;
}

int main() {
    int numCases;
    cin >> numCases;
    for (int caseNum = 1; caseNum <= numCases; caseNum++) {
        int N, S;
        cin >> N >> S;
        cin.ignore();
        vector<string> lines(N);
        for (int i = 0; i < N; i++) getline(cin, lines[i]);

        SudokuBoard shiftedBoard(N);
        shiftedBoard.parseBoard(lines);

        // Prioritize shifts based on problematic subgrids
        int sqrtN = static_cast<int>(sqrt(N));
        vector<int> problematic = getProblematicSubgrids(shiftedBoard);
        set<int> priorityRows, priorityCols;
        for (int box : problematic) {
            int boxRow = (box / sqrtN) * sqrtN;
            int boxCol = (box % sqrtN) * sqrtN;
            for (int i = 0; i < sqrtN; i++) {
                priorityRows.insert(boxRow + i);
                priorityCols.insert(boxCol + i);
            }
        }

        vector<pair<char, int>> candidates;
        for (int row : priorityRows) candidates.push_back({'R', row});
        for (int col : priorityCols) candidates.push_back({'C', col});
        for (int i = 0; i < N; i++) {
            if (priorityRows.find(i) == priorityRows.end()) {
                candidates.push_back({'R', i});
            }
        }
        for (int j = 0; j < N; j++) {
            if (priorityCols.find(j) == priorityCols.end()) {
                candidates.push_back({'C', j});
            }
        }

        vector<ShiftInfo> shifts, bestShifts;
        SudokuBoard solvedBoard(N);
        cout << "Case #" << caseNum << ": ";
        if (tryCombinations(shiftedBoard, shifts, S, candidates, 0, bestShifts, solvedBoard)) {
            for (const auto& shift : bestShifts) {
                cout << shift.type << " " << shift.index << " " << shift.amount << "\n";
            }
            const auto& solvedGrid = solvedBoard.getGrid();
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << solvedGrid[i][j];
                    if (j < N - 1) cout << " ";
                }
                cout << "\n";
            }
        } else {
            cout << "No solution found\n";
        }
    }
    return 0;
}