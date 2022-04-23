/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        dfs(s, 0, res);
        return res;
    }
    void dfs(string& s, int pos, vector<string>& res) {
        if (pos == s.size()) {
            res.push_back(s);
            return;
        }
        if (s[pos] >= 'a' && s[pos] <= 'z') {
            s[pos] = s[pos] - 'a' + 'A';
            dfs(s, pos + 1, res);
            s[pos] = s[pos] - 'A' + 'a';
        }
        else if (s[pos] >= 'A' && s[pos] <= 'Z') {
            s[pos] = s[pos] - 'A' + 'a';
            dfs(s, pos + 1, res);
            s[pos] = s[pos] - 'a' + 'A';
        }
        dfs(s, pos + 1, res);
    }
};
// @lc code=end

