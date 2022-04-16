/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string res;
        int i = 0, j = 0;
        while (i < s.size()) {
            while (i < s.size() && s[i] == ' ') {
                i++;
            }
            j = i;
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            reverse(s.begin() + i, s.begin() + j);
            res += s.substr(i, j - i);
            res += ' ';
            i = j + 1;
        }
        if (res.size() > 0) {
            res.pop_back();
        }
        return res;
    }
};
// @lc code=end

