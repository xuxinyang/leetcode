/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber > 0) {
            int remainder = columnNumber % 26;
            if (remainder == 0) {
                res = 'Z' + res;
                columnNumber = (columnNumber - 1) / 26;
            } else {
                res = char(remainder + 'A' - 1) + res;
                columnNumber = (columnNumber - remainder) / 26;
            }
        }
        return res;
    }
};
// @lc code=end

