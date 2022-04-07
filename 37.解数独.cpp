/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // 初始化数独
        vector<vector<int>> sudoku(9, vector<int>(9, 0));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    sudoku[i][j] = board[i][j] - '0';
                }
            }
        }
        
        // 开始求解
        solve(sudoku);
        
        // 输出结果
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                board[i][j] = sudoku[i][j] + '0';
            }
        }
    }

};
// @lc code=end

