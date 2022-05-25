/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> res(n, false);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur = (cur << 1) + nums[i];
            res[i] = (cur % 5 == 0);
        }
        return res;
    }
};
// @lc code=end

