/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minfreq(26, INT_MAX);
        vector<int> freq(26, 0);
        for (auto word: words) {
            fill(freq.begin(), freq.end(), 0);
            for (auto c: word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                minfreq[i] = min(minfreq[i], freq[i]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            while (minfreq[i]--) {
                ans.emplace_back(1, i + 'a');
            }
        }
        return ans;
    }
};
// @lc code=end

