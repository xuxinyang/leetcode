/*
 * @lc app=leetcode.cn id=1160 lang=cpp
 *
 * [1160] 拼写单词
 */

// @lc code=start
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        unordered_map<char, int> m;
        for (char c : chars) {
            m[c]++;
        }
        for (string &word : words) {
            unordered_map<char, int> tmp = m;
            bool flag = true;
            for (char c : word) {
                if (tmp.find(c) == tmp.end() || tmp[c] == 0) {
                    flag = false;
                    break;
                }
                tmp[c]--;
            }
            if (flag) {
                res += word.size();
            }
        }
        return res;
    }
};
// @lc code=end

