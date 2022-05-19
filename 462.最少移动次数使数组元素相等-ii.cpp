/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最少移动次数使数组元素相等 II
 */

// @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mid = nums[n / 2];
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += abs(nums[i] - mid);
        }
        return res;
    }
};
// @lc code=end

