/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            if (nums[i] * nums[i] <= nums[j] * nums[j]) {
                res.push_back(nums[i] * nums[i]);
                i++;
            } else {
                res.push_back(nums[j] * nums[j]);
                j--;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

