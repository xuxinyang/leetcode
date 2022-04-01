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
        int l = 0, r = n - 1;
        int res = 0;
        int left_max = 0, right_max = 0;
        while (l < r) {
            left_max = max(left_max, height[l]);
            right_max = max(right_max, height[r]);
            if (left_max < right_max) {
                res += left_max - height[l];
                l++;
            } else {
                res += right_max - height[r];
                r--;
            }
        }
        return res;
    }
};
// @lc code=end

