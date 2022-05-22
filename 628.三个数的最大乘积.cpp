/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[n - 1] * nums[n - 2] * nums[n - 3];
        if (nums[0] < 0) {
            res = max(res, nums[0] * nums[1] * nums[n - 1]);
        }
        return res;
    }
};
// @lc code=end

