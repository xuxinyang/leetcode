/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, visited, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& word, int index) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }
        if (board[i][j] != word[index]) {
            return false;
        }
        if (visited[i][j]) {
            return false;
        }
        visited[i][j] = true;
        bool res = dfs(board, visited, i + 1, j, word, index + 1) || dfs(board, visited, i - 1, j, word, index + 1) || dfs(board, visited, i, j + 1, word, index + 1) || dfs(board, visited, i, j - 1, word, index + 1);
        visited[i][j] = false;
        return res;
    }
};
// @lc code=end

