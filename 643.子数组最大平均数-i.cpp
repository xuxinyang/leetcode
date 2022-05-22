/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        double res = sum * 1.0 / k;
        for (int i = k; i < n; ++i) {
            sum += nums[i] - nums[i - k];
            res = max(res, sum * 1.0 / k);
        }
        return res;
    }
};
// @lc code=end

