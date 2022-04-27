/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int l = 0, r = 1;
        int maxx = nums[0];
        int sum = nums[0];
        while (r < n)
        {
            if (sum + nums[r] > nums[r])
            {
                sum += nums[r];
                r++;
            }
            else
            {
                sum = nums[r];
                l = r;
                r++;
            }
            maxx = max(maxx, sum);
        }
        return maxx;
    }
};
// @lc code=end

