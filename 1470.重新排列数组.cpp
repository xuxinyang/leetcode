/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
 */

// @lc code=start
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(2 * n, 0);
        int j = 0;
        for (int i = 0; i < nums.size() / 2; i++)
        {
            res[j] = nums[i];
            res[j + 1] = nums[nums.size() / 2 + i];
            j += 2;
        }
        return res;
    }
};
// @lc code=end

