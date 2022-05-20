/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int min = *min_element(nums.begin(), nums.end());
        for (auto i : nums) {
            ans += i - min;
        }
        return ans;
    }
};
// @lc code=end

