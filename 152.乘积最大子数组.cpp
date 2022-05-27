/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int dp_i_0 = nums[0], dp_i_1 = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            int temp = dp_i_0;
            dp_i_0 = max(max(dp_i_0 * nums[i], dp_i_1 * nums[i]), nums[i]);
            dp_i_1 = min(min(temp * nums[i], dp_i_1 * nums[i]), nums[i]);
            res = max(res, dp_i_0);
        }
        return res;
    }
};
// @lc code=end

