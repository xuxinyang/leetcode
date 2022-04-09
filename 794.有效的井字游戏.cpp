/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 */

// @lc code=start
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        vector<int> diag(2, 0);
        vector<int> anti_diag(2, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'X') {
                    row[i]++;
                    col[j]++;
                    if (i == j) {
                        diag[0]++;
                    }
                    if (i + j == n - 1) {
                        anti_diag[0]++;
                    }
                } else if (board[i][j] == 'O') {
                    row[i]--;
                    col[j]--;
                    if (i == j) {
                        diag[1]--;
                    }
                    if (i + j == n - 1) {
                        anti_diag[1]--;
                    }
                }
            }
        }
        if (row[0] == 0 || row[1] == 0) {
            return false;
        }
        if (col[0] == 0 || col[1] == 0) {
            return false;
        }
        if (diag[0] == 0 || diag[1] == 0) {
            return false;
        }
        if (anti_diag[0] == 0 || anti_diag[1] == 0) {
            return false;
        }
        return true;
    }
};
// @lc code=end

