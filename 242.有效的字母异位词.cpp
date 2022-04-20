/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> v(26, 0);
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a']++;
            v[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (v[i] != 0) return false;
        }
        return true;
    }
};
// @lc code=end

