/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
 */

// @lc code=start
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ans(101, 0);
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            ans[i] = heights[i];
        }
        sort(heights.begin(), heights.end());
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != ans[i]) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

