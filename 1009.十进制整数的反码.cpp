/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int n) {
        int res = 0;
        int i = 0;
        while (n) {
            res += (n & 1) ^ 1;
            n >>= 1;
            res <<= 1;
            i++;
        }
        return res >> i;
    }
};
// @lc code=end

