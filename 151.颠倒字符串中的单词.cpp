/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 颠倒字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            res.push_back(word);
        }
        reverse(res.begin(), res.end());
        string res_str = "";
        for (auto &word : res) {
            res_str += word + " ";
        }
        return res_str.substr(0, res_str.size() - 1);
    }
};
// @lc code=end

