/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        vector<int> res(n, 0);
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        for (int i = n - 1; i >= 0; --i) {
            int index = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
            res[i] = index;
        }
        return res;
    }
};
// @lc code=end

