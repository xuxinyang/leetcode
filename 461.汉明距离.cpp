/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int tmp = x ^ y;
        while (tmp) {
            res += tmp & 1;
            tmp = tmp >> 1;
        }
        return res;
    }
};
// @lc code=end

