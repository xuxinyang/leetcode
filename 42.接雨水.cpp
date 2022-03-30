/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int m = height[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (height[i] > m) m = height[i];
            else {
                ans += m - height[i];
            }
        }
        m = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (height[i] > m) m = height[i];
            else {
                ans += m - height[i];
            }
        }
        return ans;
    }
};
// @lc code=end

