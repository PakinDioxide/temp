#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const int N = 4;
const int SEARCH_DEPTH = 3;  // Adjust depth for better performance

// Read the game board
void read_board(vector<vector<int>> &board) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

// Merge row according to 2048 rules (used for left move)
vector<int> mergeRow(const vector<int>& row) {
    vector<int> filtered;
    for (int x : row) {
        if(x != 0) 
            filtered.push_back(x);
    }
    vector<int> merged;
    for (int i = 0; i < filtered.size(); ++i) {
        if(i + 1 < filtered.size() && filtered[i] == filtered[i+1]) {
            merged.push_back(filtered[i] * 2);
            i++; // Skip the next one
        } else {
            merged.push_back(filtered[i]);
        }
    }
    while(merged.size() < 4)
        merged.push_back(0);
    return merged;
}

// Move left
vector<vector<int>> moveLeft(const vector<vector<int>> &board) {
    vector<vector<int>> newBoard(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        newBoard[i] = mergeRow(board[i]);
    }
    return newBoard;
}

// Move right
vector<vector<int>> moveRight(const vector<vector<int>> &board) {
    vector<vector<int>> newBoard = board;
    for (int i = 0; i < N; ++i) {
        vector<int> revRow = board[i];
        reverse(revRow.begin(), revRow.end());
        revRow = mergeRow(revRow);
        reverse(revRow.begin(), revRow.end());
        newBoard[i] = revRow;
    }
    return newBoard;
}

// Transpose (for moving up/down)
vector<vector<int>> transpose(const vector<vector<int>> &board) {
    vector<vector<int>> newBoard(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            newBoard[j][i] = board[i][j];
    return newBoard;
}

// Move up
vector<vector<int>> moveUp(const vector<vector<int>> &board) {
    vector<vector<int>> t = transpose(board);
    t = moveLeft(t);
    return transpose(t);
}

// Move down
vector<vector<int>> moveDown(const vector<vector<int>> &board) {
    vector<vector<int>> t = transpose(board);
    t = moveRight(t);
    return transpose(t);
}

// Check if the board changed after a move
bool boardChanged(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if(a[i][j] != b[i][j])
                return true;
    return false;
}

// Simulate a move and check if it's valid
pair<vector<vector<int>>, bool> moveBoard(const vector<vector<int>> &board, char dir) {
    vector<vector<int>> newBoard;
    if (dir == 'L')
        newBoard = moveLeft(board);
    else if (dir == 'R')
        newBoard = moveRight(board);
    else if (dir == 'U')
        newBoard = moveUp(board);
    else if (dir == 'D')
        newBoard = moveDown(board);
    else
        newBoard = board;
    
    return {newBoard, boardChanged(board, newBoard)};
}

// **Heuristic Evaluation Function**
double heuristic(const vector<vector<int>> &board) {
    int empty = 0;
    int maxTile = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            if(board[i][j] == 0) ++empty;
            else maxTile = max(maxTile, board[i][j]);
        }
    return empty * 1000 + maxTile; // More empty spaces are prioritized
}

// **Expectimax Search Algorithm**
double expectimax(const vector<vector<int>> &board, int depth, bool isPlayerTurn) {
    if(depth == 0) {
        return heuristic(board);
    }
    
    if(isPlayerTurn) {
        double best = -1e9;
        bool moveFound = false;
        for (char move : {'L', 'R', 'U', 'D'}) {
            auto [newBoard, moved] = moveBoard(board, move);
            if(!moved) continue;
            moveFound = true;
            double value = expectimax(newBoard, depth - 1, false);
            best = max(best, value);
        }
        if(!moveFound) return heuristic(board);
        return best;
    } else {
        vector<pair<int,int>> empties;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if(board[i][j] == 0)
                    empties.push_back({i, j});
        if(empties.empty()) return heuristic(board);
        double expected = 0;
        for(auto [i, j] : empties) {
            vector<vector<int>> board2 = board, board4 = board;
            board2[i][j] = 2;
            board4[i][j] = 4;
            double val2 = expectimax(board2, depth - 1, true);
            double val4 = expectimax(board4, depth - 1, true);
            expected += 0.9 * val2 + 0.1 * val4;
        }
        expected /= empties.size();
        return expected;
    }
}

// **Find the Best Move**
char best_move(const vector<vector<int>> &board) {
    char bestDir = 'L';
    double bestScore = -1e9;
    for (char move : {'L', 'R', 'U', 'D'}) {
        auto [newBoard, moved] = moveBoard(board, move);
        if(!moved) continue;
        double score = expectimax(newBoard, SEARCH_DEPTH, false);
        if(score > bestScore) {
            bestScore = score;
            bestDir = move;
        } 
    }
    return bestDir;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<vector<int>> board(N, vector<int>(N));
    
    while(true) {
        read_board(board);
        if(board[0][0] == -1) break; // Game over
        
        char move = best_move(board);
        cout << move << "\n";
        cout.flush();
    }
    
    return 0;
}
