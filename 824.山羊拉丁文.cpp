/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */

// @lc code=start
class Solution {
public:
    string toGoatLatin(string sentence) {
        string res;
        int i = 1;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u' || word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U') {
                res += word + "ma";
            } else {
                res += word.substr(1) + word[0] + "ma";
            }
            for (int j = 0; j < i; j++) {
                res += 'a';
            }
            i++;
            res += " ";
        }
        return res.substr(0, res.size() - 1);
    }
};
// @lc code=end

