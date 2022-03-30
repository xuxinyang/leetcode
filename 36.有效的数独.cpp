/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return false;
        int m = board[0].size();
        if (m == 0) return false;
        // check row
        for (int i = 0; i < n; i++) {
            unordered_set<char> s;
            for (int j = 0; j < m; j++) {
                if (board[i][j] != '.') {
                    if (s.find(board[i][j]) != s.end()) return false;
                    s.insert(board[i][j]);
                }
            }
        }
        // check column
        for (int j = 0; j < m; j++) {
            unordered_set<char> s;
            for (int i = 0; i < n; i++) {
                if (board[i][j] != '.') {
                    if (s.find(board[i][j]) != s.end()) return false;
                    s.insert(board[i][j]);
                }
            }
        }
        // check block
        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < m; j += 3) {
                unordered_set<char> s;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (board[i + x][j + y] != '.') {
                            if (s.find(board[i + x][j + y]) != s.end()) return false;
                            s.insert(board[i + x][j + y]);
                        }
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

