/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 */

// @lc code=start
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words)  {
        unordered_set<string> good(words.begin(), words.end());
        for (const string &word: words) {
            for (int k = 1; k < word.size(); ++k) {
                good.erase(word.substr(k));
            }
        }
        int ans = 0;
        for (const string & word: good) {
            ans += word.size() + 1;
        }
        return ans;
    }
};
// @lc code=end

