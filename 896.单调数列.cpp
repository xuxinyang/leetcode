/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool flag = true, increment = true;
        int i = 0;
        if (nums[0] <= nums[n - 1]) {
            increment = true;
            while (i < n - 1) {
                if (nums[i] > nums[i + 1]) {
                    flag = false;
                    break;
                }
                i++;
            }
        } else {
            increment = false;
            while (i < n - 1) {
                if (nums[i] < nums[i + 1]) {
                    flag = false;
                    break;
                }
                i++;
            }
        }
        return flag;
    }
};
// @lc code=end

