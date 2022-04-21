/*
 * @lc app=leetcode.cn id=1760 lang=cpp
 *
 * [1760] 袋子里最少数目的球
 */

// @lc code=start
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations)
    {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while (left <= right) {
            int y = (left + right) / 2;
            long sum = 0;
            for (int x : nums) {
                sum += (x - 1) / y;
            }
            if (sum <= maxOperations) {
                ans = y;
                right = y - 1;
            } else {
                left = y + 1;
            }
        }
        return ans;
    }

};
// @lc code=end

