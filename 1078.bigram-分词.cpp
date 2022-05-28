/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 */

// @lc code=start
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        stringstream ss(text);
        string tmp;
        ss >> tmp;
        while (ss >> tmp) {
            if (tmp == first) {
                ss >> tmp;
                if (tmp == second) {
                    ss >> tmp;
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};
// @lc code=end

