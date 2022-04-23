/*
 * @lc app=leetcode.cn id=1283 lang=cpp
 *
 * [1283] 使结果不超过阈值的最小除数
 */

// @lc code=start
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 1, r = nums[n - 1];
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, nums, threshold)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
private:
    bool check(int x, vector<int>& nums, int threshold) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] + x - 1) / x;
        }
        return sum <= threshold;
    }
};
// @lc code=end

