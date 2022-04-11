/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int tmp = num;
        int n = 0;
        while (tmp) {
            tmp = tmp >> 1;
            n++;
        }
        for (int i = 0; i < n; i++) {
            res += (num >> i) & 1 ? 0 : 1 << i;
        }
        return res;
    }
};
// @lc code=end

