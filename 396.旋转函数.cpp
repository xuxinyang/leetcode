/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();
        int f = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            f += i * nums[i];
        }
        int max = f;
        for (int i = len - 1; i >= 0; i--) {
            f = f + sum - len * nums[i];
            max = max > f ? max : f;
        }
        return max;
    }
};
// @lc code=end

