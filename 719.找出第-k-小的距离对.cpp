/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 k 小的距离对
 */

// @lc code=start
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[n - 1] - nums[0];
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for (int i = 0, j = 0; i < n; ++i) {
                while (j < n && nums[j] - nums[i] <= mid) {
                    ++j;
                }
                cnt += j - i - 1;
            }
            if (cnt >= k) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

