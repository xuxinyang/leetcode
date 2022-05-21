/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> col(n, 0);
        vector<int> pie(2 * n - 1, 0);
        vector<int> na(2 * n - 1, 0);
        dfs(res, board, col, pie, na, 0, n);
        return res;
    }
    void dfs(vector<vector<string>>& res, vector<string>& board, vector<int>& col, vector<int>& pie, vector<int>& na, int row, int n) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (col[i] || pie[row + i] || na[row - i + n - 1]) {
                continue;
            }
            col[i] = 1;
            pie[row + i] = 1;
            na[row - i + n - 1] = 1;
            board[row][i] = 'Q';
            dfs(res, board, col, pie, na, row + 1, n);
            board[row][i] = '.';
            col[i] = 0;
            pie[row + i] = 0;
            na[row - i + n - 1] = 0;
        }
    }
};
// @lc code=end

