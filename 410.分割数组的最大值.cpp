/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (m == 1) return *max_element(nums.begin(), nums.end());
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (check(nums, mid, m))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

