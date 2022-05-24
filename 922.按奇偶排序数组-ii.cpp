/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && nums[i] % 2 == 0 && i % 2 == 0) {
                i++;
            }
            while (i < j && nums[j] % 2 == 1 && j % 2 == 1) {
                j--;
            }
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};
// @lc code=end

