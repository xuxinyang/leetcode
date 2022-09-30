/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> P(n+1);
        for (int i = 1; i <= n; i++) {
            P[i] = P[i-1] + (1 - nums[i-1]);
        }
        int ans = 0;
        for (int right = 0; right < n; ++right) {
            int left = lower_bound(P.begin(), P.end(), P[right + 1] - k) - P.begin();
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

