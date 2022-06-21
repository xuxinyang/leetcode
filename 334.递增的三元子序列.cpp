/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        int a = INT_MAX, b = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= a) {
                a = nums[i];
            } else if (nums[i] <= b) {
                b = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

