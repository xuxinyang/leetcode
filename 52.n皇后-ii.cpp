/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> cols(n, 0);
        vector<int> pie(2 * n - 1, 0);
        vector<int> na(2 * n - 1, 0);
        dfs(ans, 0, cols, pie, na, n);
        return ans;
    }
    void dfs(int& ans, int row, vector<int>& cols, vector<int>& pie, vector<int>& na, int n) {
        if (row == n) {
            ans++;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (cols[i] || pie[row + i] || na[row - i + n - 1]) {
                continue;
            }
            cols[i] = 1;
            pie[row + i] = 1;
            na[row - i + n - 1] = 1;
            dfs(ans, row + 1, cols, pie, na, n);
            cols[i] = 0;
            pie[row + i] = 0;
            na[row - i + n - 1] = 0;
        }
    }
};
// @lc code=end

