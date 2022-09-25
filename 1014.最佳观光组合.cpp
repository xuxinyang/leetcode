/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, mx = values[0] + 0;
        for (int j = 1; j < values.size(); ++j)
        {
            ans = max(ans, mx + values[j]-j);
            mx = max(mx, values[j]+j);
        }
        return ans;
    }
};
// @lc code=end

