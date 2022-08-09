/*
 * @lc app=leetcode.cn id=910 lang=cpp
 *
 * [910] 最小差值 II
 */

// @lc code=start
class Solution
{
public:
    int smallestRangeII(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n - 1] - nums[0];
        for (int i = 0; i < n - 1; ++i)
        {
            int l = min(nums[0] + k, nums[i + 1] - k);
            int r = max(nums[n - 1] - k, nums[i] + k);
            ans = min(ans, r - l);
        }
        return ans;
    }
};
// @lc code=end
