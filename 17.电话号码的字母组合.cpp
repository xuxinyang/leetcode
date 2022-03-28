/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        string str = "";
        dfs(digits, 0, str, res);
        return res;
    }
    void dfs(string digits, int index, string str, vector<string>& res) {
        if (index == digits.size()) {
            res.push_back(str);
            return;
        }
        string letters = getLetters(digits[index]);
        for (int i = 0; i < letters.size(); i++) {
            str += letters[i];
            dfs(digits, index + 1, str, res);
            str.pop_back();
        }
    }
    string getLetters(char c) {
        switch (c) {
            case '2':
                return "abc";
            case '3':
                return "def";
            case '4':
                return "ghi";
            case '5':
                return "jkl";
            case '6':
                return "mno";
            case '7':
                return "pqrs";
            case '8':
                return "tuv";
            case '9':
                return "wxyz";
            default:
                return "";
        }
    }
};
// @lc code=end

