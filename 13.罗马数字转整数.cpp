/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == 'I') {
                if (i + 1 < s.length() && s[i + 1] == 'V') {
                    res += 4;
                    i += 2;
                } else if (i + 1 < s.length() && s[i + 1] == 'X') {
                    res += 9;
                    i += 2;
                } else {
                    res += 1;
                    i++;
                }
            } else if (s[i] == 'V') {
                res += 5;
                i++;
            } else if (s[i] == 'X') {
                if (i + 1 < s.length() && s[i + 1] == 'L') {
                    res += 40;
                    i += 2;
                } else if (i + 1 < s.length() && s[i + 1] == 'C') {
                    res += 90;
                    i += 2;
                } else {
                    res += 10;
                    i++;
                }
            } else if (s[i] == 'L') {
                res += 50;
                i++;
            } else if (s[i] == 'C') {
                if (i + 1 < s.length() && s[i + 1] == 'D') {
                    res += 400;
                    i += 2;
                } else if (i + 1 < s.length() && s[i + 1] == 'M') {
                    res += 900;
                    i += 2;
                } else {
                    res += 100;
                    i++;
                }
            } else if (s[i] == 'D') {
                res += 500;
                i++;
            } else if (s[i] == 'M') {
                res += 1000;
                i++;
            }
        }
        return res;
    }
};
// @lc code=end

