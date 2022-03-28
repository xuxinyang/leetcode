/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<string>& res, string& num, string& path, int index) {
        if (index == num.size()) {
            res.push_back(path);
            return;
        }
        for (int i = index; i < num.size(); i++) {
            if (i != index && num[index] == num[i]) {
                continue;
            }
            path.push_back(num[index]);
            dfs(res, num, path, i + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        string str = "";
        dfs(digits, 0, str, res);
        return res;
    }
};
// @lc code=end

