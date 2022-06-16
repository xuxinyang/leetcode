/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 统计各位数字都不同的数字个数
 */

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int res = 10;
        int uniqueDigits = 9;
        for (int i = 2; i <= n; ++i) {
            uniqueDigits *= (10 - i + 1);
            res += uniqueDigits;
        }
        return res;
    }
};
// @lc code=end

