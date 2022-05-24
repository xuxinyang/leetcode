/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
 */

// @lc code=start
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        for (auto c : s1) {
            if (c == ' ') {
                continue;
            }
            ++m[c];
        }
        for (auto c : s2) {
            if (c == ' ') {
                continue;
            }
            ++m[c];
        }
        vector<string> ans;
        for (auto p : m) {
            if (p.second == 1) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};
// @lc code=end

