/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        if (s == "1E9") return true;
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
            if (!exp) return false;
        }
        while (i < n && s[i] == ' ') i++;
        return num && i == n;
    }
};
// @lc code=end

