/*
 * @lc app=leetcode.cn id=1608 lang=cpp
 *
 * [1608] 特殊数组的特征值
 */

// @lc code=start
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 1, r = n;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[n-mid] >= mid)
            {
                if (n - mid > 0 && nums[n-mid-1] < mid)
                {
                    return mid;
                }
                if (n - mid <= 0)
                {
                    return mid;
                }
            }
            if (nums[n-mid] >= mid)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

