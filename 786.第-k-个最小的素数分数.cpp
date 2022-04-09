/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的素数分数
 */

// @lc code=start
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0) return {};
        vector<int> dp(n, 0);
        int res = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (arr[i] > arr[j]) {
                    dp[j]++;
                }
            }
            res += dp[i];
            if (res >= k) {
                return {arr[i], arr[i + 1]};
            }
        }
        return {};
    }
};
// @lc code=end

