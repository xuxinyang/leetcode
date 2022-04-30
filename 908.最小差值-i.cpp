/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min_num = INT_MAX, max_num = INT_MIN;
        for (int num : nums) {
            min_num = min(min_num, num);
            max_num = max(max_num, num);
        }
        return max(0, max_num - min_num - 2 * k);
    }
};
// @lc code=end

