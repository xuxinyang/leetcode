/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        for (int i = 0; i < timeSeries.size(); ++i) {
            if (i == 0 || timeSeries[i] - timeSeries[i - 1] >= duration) {
                ans += duration;
            } else {
                ans += timeSeries[i] - timeSeries[i - 1];
            }
        }
        return ans;
    }
};
// @lc code=end

