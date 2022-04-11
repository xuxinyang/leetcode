/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        // 处理正数和负数的情况
        if (num == 0) return "0";
        string res = "";
        int n = 0;
        if (num < 0) {
            n = 1;
            num = -num;
        }
        while (num) {
            int tmp = num & 15;
            if (tmp < 10) {
                res = to_string(tmp) + res;
            } else {
                res = char(tmp - 10 + 'a') + res;
            }
            num = num >> 4;
        }
        if (n) {
            res = "-" + res;
        }
        return res;
    }
};
// @lc code=end

