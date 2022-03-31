/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {

        if (n == 0) {
            return 1;
        }
        if (x == -1 && n % 2 == 0) {
            return -x;
        }
        if (x == 1 || x == -1) {
            return x;
        }
        if (n == INT_MAX || n == INT_MIN) {
            return 0;
        }
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        double res = 1;
        while (n) {
            if (n & 1) {
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    }
};
// @lc code=end

