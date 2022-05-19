/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        for (int i = 0; i < s.size(); ++i) {
            if (m1.find(s[i]) == m1.end() && m2.find(t[i]) == m2.end()) {
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            } else if (m1[s[i]] != t[i] || m2[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

