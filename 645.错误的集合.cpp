/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(2, 0);
        for (int i = 0; i < n; ++i) {
            if (nums[abs(nums[i]) - 1] < 0) {
                res[0] = abs(nums[i]);
            } else {
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                res[1] = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end

