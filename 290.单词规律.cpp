/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> um;
        unordered_map<string, char> um2;
        stringstream ss(s);
        string word;
        int i = 0;
        while (getline(ss, word, ' ')) {
            if (um.count(pattern[i]) == 0) {
                if (um2.count(word) == 0) {
                    um[pattern[i]] = word;
                    um2[word] = pattern[i];
                    i++;
                } else {
                    return false;
                }
            } else {
                if (um[pattern[i]] != word) {
                    return false;
                }
                i++;
            }
        }
        return i == pattern.size();
    }
};
// @lc code=end

