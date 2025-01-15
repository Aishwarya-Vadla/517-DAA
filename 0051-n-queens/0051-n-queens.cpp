#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.')); // Initialize board with '.'
        vector<bool> columns(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
        solve(0, n, board, solutions, columns, diag1, diag2);
        return solutions;
    }

private:
    void solve(int row, int n, vector<string>& board, vector<vector<string>>& solutions,
               vector<bool>& columns, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (columns[col] || diag1[row - col + n - 1] || diag2[row + col]) {
                continue;
            }
            board[row][col] = 'Q'; // Place the queen
            columns[col] = diag1[row - col + n - 1] = diag2[row + col] = true;
            solve(row + 1, n, board, solutions, columns, diag1, diag2); // Recurse
            board[row][col] = '.'; // Remove the queen (backtrack)
            columns[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        }
    }
};
