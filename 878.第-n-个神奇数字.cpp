/*
 * @lc app=leetcode.cn id=878 lang=cpp
 *
 * [878] 第 N 个神奇数字
 */

// @lc code=start
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        const int mod = 1e9+7;
        long long l = min(a, b);
        long long r = (long long)n * min(a, b);
        int c = lcm(a, b);
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            long long cnt = mid / a + mid / b - mid / c;
            if (cnt >= n) r = mid - 1;
            else l = mid + 1;
        }
        return (r + 1) % mod;
    }
};
// @lc code=end

