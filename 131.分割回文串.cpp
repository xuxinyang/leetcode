/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, path, res);
        return res;
    }
    void dfs(string s, vector<string>& path, vector<vector<string>>& res) {
        if (s.empty()) {
            res.push_back(path);
            return;
        }
        for (int i = 1; i <= s.size(); i++) {
            if (isPalindrome(s.substr(0, i))) {
                path.push_back(s.substr(0, i));
                dfs(s.substr(i), path, res);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
// @lc code=end

