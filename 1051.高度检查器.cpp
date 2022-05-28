/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
 */

// @lc code=start
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> dp(101, 0);
        for (int i = 0; i < heights.size(); i++) {
            dp[heights[i]]++;
        }
        int res = 0;
        for (int i = 1; i < dp.size(); i++) {
            int cnt = dp[i];
            while (cnt--) {
                if (heights[res++] != i) {
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

