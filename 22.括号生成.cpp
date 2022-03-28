/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path = "";
        dfs(res, path, n, n);
        return res;
    }
    void dfs(vector<string>& res, string& path, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(path);
            return;
        }
        if (left > 0) {
            path.push_back('(');
            dfs(res, path, left - 1, right);
            path.pop_back();
        }
        if (right > left) {
            path.push_back(')');
            dfs(res, path, left, right - 1);
            path.pop_back();
        }
    }
};
// @lc code=end

