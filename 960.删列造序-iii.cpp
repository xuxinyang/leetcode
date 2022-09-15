/*
 * @lc app=leetcode.cn id=960 lang=cpp
 *
 * [960] 删列造序 III
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size();
        int col = strs[0].size();
        vector<int> dp(col, 1);
        for (int i = 0; i < col; i++) {
            for (int j = i + 1; j < col; j++) {
                bool flag = true;
                for (int r = 0; r < row; r++) {
                    if (strs[r][j] < strs[r][i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        return col - *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

