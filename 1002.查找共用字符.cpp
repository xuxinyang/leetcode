/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> mp(26, 0);
        for (auto& w : words) {
            vector<int> tmp(26, 0);
            for (auto& c : w) {
                tmp[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                mp[i] = min(mp[i], tmp[i]);
            }
        }
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            while (mp[i]-- > 0) {
                res.push_back(string(1, 'a' + i));
            }
        }
        return res;
    }
};
// @lc code=end

