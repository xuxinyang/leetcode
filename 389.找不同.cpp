/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n == 0) return t[0];
        if (m == 0) return '\0';
        char res = '\0';
        for (int i = 0; i < n; i++) {
            res ^= s[i];
        }
        for (int i = 0; i < m; i++) {
            res ^= t[i];
        }
        return res;
    }
};
// @lc code=end

