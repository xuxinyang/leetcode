/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int n) {
        int high = 0;
        for (int i = 1; i <= 30; i++)
        {
            if (n >= (1 << i))
            {
                high = i;
            }
            else
            {
                break;
            }
        }
        int mask = (high == 30 ? 0x7fffffff : (1 << (high + 1)) - 1);
        return n ^ mask;
    }
};
// @lc code=end

