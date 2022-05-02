/*
 * @lc app=leetcode.cn id=1508 lang=cpp
 *
 * [1508] 子数组和排序后的区间和
 */

// @lc code=start
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        int sumLength = n * (n + 1) / 2;
        auto sums = vector<int>(sumLength, 0);
        int index = 0;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                sums[index++] = sum;
            }
        }
        sort(sums.begin(), sums.end());
        int res = 0;
        for (int i = left - 1; i < right; ++i) {
            res = (res + sums[i]) % MOD;
        }
        return res;
    }
};
// @lc code=end

