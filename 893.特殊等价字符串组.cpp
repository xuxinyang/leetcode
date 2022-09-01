/*
 * @lc app=leetcode.cn id=893 lang=cpp
 *
 * [893] 特殊等价字符串组
 */

// @lc code=start
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> se;
        for (const auto &word : words) {
            string even, odd;
            for (int i = 0; i < word.size(); i++)
            {
                if (i % 2) odd += word[i];
                else even += word[i];
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            se.insert(odd + even);
        }
        return se.size();
    }
};
// @lc code=end

