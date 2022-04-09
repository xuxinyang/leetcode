/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int j = 0; j < nums.size(); ++j) {
                cnt += (nums[j] >> i) & 1;
            }
            res |= (cnt % 3) << i;
        }
        return res;
    }
};
// @lc code=end

