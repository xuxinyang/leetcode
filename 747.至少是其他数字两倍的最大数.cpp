/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max_num = 0xC0C0C0C0;
        int max_idx = -1;
        int second_max_num = 0xC0C0C0C0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > max_num) {
                second_max_num = max_num;
                max_num = nums[i];
                max_idx = i;
            } else if (nums[i] > second_max_num) {
                second_max_num = nums[i];
            }
        }
        return max_num >= second_max_num * 2 ? max_idx : -1;
    }
};
// @lc code=end

