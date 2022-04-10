/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        int cnt = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            ++cnt;
        }
        res = left << cnt;
        return res;
    }
};
// @lc code=end

