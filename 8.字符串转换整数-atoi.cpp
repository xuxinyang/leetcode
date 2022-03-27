/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int sign = 1;
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        }
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + (s[i] - '0');
            i++;
        }
        return res * sign;
    }
};
// @lc code=end

