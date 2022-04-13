/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        dfs(s, 0, 0, res);
        return res;
    }
private:
    void dfs(string s, int start, int count, vector<string>& res) {
        if (count < 0) {
            return;
        }
        if (start == s.size()) {
            if (count == 0) {
                res.push_back(s);
            }
            return;
        }
        if (s[start] == '(') {
            dfs(s, start+1, count+1, res);
        } else if (s[start] == ')') {
            dfs(s, start+1, count-1, res);
        } else {
            dfs(s, start+1, count, res);
        }
        if (s[start] != '(' && s[start] != ')') {
            s[start] = '#';
            dfs(s, start+1, count, res);
            s[start] = s[start-1];
        }
    }

};
// @lc code=end

