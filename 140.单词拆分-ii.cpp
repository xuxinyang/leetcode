/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> res;
        vector<string> path;
        dfs(s, dict, path, res);
        return res;
    }
    void dfs(string s, unordered_set<string>& dict, vector<string>& path, vector<string>& res) {
        if (s.empty()) {
            string tmp;
            for (int i = 0; i < path.size(); i++) {
                tmp += path[i];
                if (i != path.size() - 1) tmp += " ";
            }
            res.push_back(tmp);
            return;
        }
        for (int i = 1; i <= s.size(); i++) {
            string word = s.substr(0, i);
            if (dict.count(word)) {
                path.push_back(word);
                dfs(s.substr(i), dict, path, res);
                path.pop_back();
            }
        }
    }
};
// @lc code=end

