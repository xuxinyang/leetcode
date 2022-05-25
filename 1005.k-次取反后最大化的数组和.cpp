/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                if (k > 0) {
                    nums[i] = -nums[i];
                    k--;
                } else {
                    sum += nums[i];
                }
            } else {
                sum += nums[i];
            }
        }
        return sum;
    }
};
// @lc code=end

