/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> m;
        int n = s.size();
        for (int i = 0; i <= n - 10; ++i) {
            string t = s.substr(i, 10);
            if (++m[t] == 2) res.push_back(t);
        }

        return res;
    }
};
// @lc code=end

