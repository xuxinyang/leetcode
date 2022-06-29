/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) {
            return 0;
        }
        int ret = 0;
        long long exp = 1;
        while (n / exp > 0) {
            int a = n / exp % 10;
            long long b = n / (exp * 10);
            if (a > 1) {
                ret += (b + 1) * exp;
            } else if (a == 1) {
                ret += b * exp + n % exp + 1;
            } else {
                ret += b * exp;
            }
            exp *= 10;
        }
        return ret;
    }
};
// @lc code=end

