/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> v1(26, 0), v2(26, 0);
        for (char c : s1) {
            v1[c - 'a']++;
        }
        for (int i = 0; i < s2.size(); i++) {
            v2[s2[i] - 'a']++;
            if (i >= s1.size()) {
                v2[s2[i - s1.size()] - 'a']--;
            }
            if (v1 == v2) return true;
        }
        return false;
    }
};
// @lc code=end

