/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == ' ') i++;
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;
        bool num = false;
        while (i < n && isdigit(s[i])) {
            num = true;
            i++;
        }
        if (i < n && s[i] == '.') {
            i++;
            while (i < n && isdigit(s[i])) {
                num = true;
                i++;
            }
        }
        if (i < n && s[i] == 'e') {
            i++;
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;
            bool exp = false;
            while (i < n && isdigit(s[i])) {
                exp = true;
                i++;
            }
            if (!exp) return 0;
        }
        while (i < n && s[i] == ' ') i++;
        if (!num || i != n) return 0;
        return 1;
    }
};
// @lc code=end

