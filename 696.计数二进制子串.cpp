/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, pre = 0, cur = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                cur++;
            } else {
                res += min(pre, cur);
                pre = cur;
                cur = 1;
            }
        }
        return res + min(pre, cur);
    }
};
// @lc code=end

