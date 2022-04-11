/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int tmp = n ^ (n >> 1);
        return tmp & (tmp + 1);
    }
};
// @lc code=end

