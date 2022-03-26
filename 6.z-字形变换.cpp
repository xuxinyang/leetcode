/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int len = s.length();
        int cycle = 2 * numRows - 2;
        string res;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < len; j += cycle) {
                res += s[j];
                if (i != 0 && i != numRows - 1 && j + cycle - 2 * i < len) {
                    res += s[j + cycle - 2 * i];
                }
            }
        }
        return res;
    }
};
// @lc code=end

