/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int res = nums[0];
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == res) {
                ++cnt;
            } else {
                --cnt;
                if (cnt == 0) {
                    res = nums[i];
                    cnt = 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end

