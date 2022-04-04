/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                int left = mid, right = mid;
                while (left >= 0 && nums[left] == target) --left;
                while (right < n && nums[right] == target) ++right;
                return {left + 1, right - 1};
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return {-1, -1};
    }
};
// @lc code=end

