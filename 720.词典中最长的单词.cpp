/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() == b.size() ? a < b : a.size() > b.size();
        });
        unordered_set<string> s;
        for (const auto& word : words) {
            if (word.size() == 1 || s.count(word.substr(0, word.size() - 1))) {
                s.insert(word);
            }
        }
        return *s.begin();
    }
};
// @lc code=end

