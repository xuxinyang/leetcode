/*
 * @lc app=leetcode.cn id=1838 lang=cpp
 *
 * [1838] 最高频元素的频数
 */

// @lc code=start
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long tol = 0;
        int l = 0, res = 1;
        for (int r = 1; r < n; r++)
        {
            tol += (long long) (nums[r] - nums[r-1]) * (r - l);
            while (tol > k) 
            {
                tol -= nums[r] - nums[l];
                l++;
            }
            res = max(res, r - l + 1);

        }
        return res;
    }
};
// @lc code=end

