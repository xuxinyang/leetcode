/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first_max = 0, second_max = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] >= first_max)
            {
                second_max = first_max;
                first_max = nums[i];
            }
            else if (nums[i] > second_max)
            {
                second_max = nums[i];
            }
        }
        return (first_max - 1) * (second_max - 1);
    }
};
// @lc code=end

