/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */

// @lc code=start
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i].size() > words[j].size()) {
                    dp[j]++;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i].size() < words[j].size()) {
                    dp[i] += dp[j];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            dp[i] += i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i].size() == words[j].size()) {
                    dp[i] += dp[j];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i].size() == words[j].size()) {
                    dp[j] += dp[i];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i].size() == words[j].size()) {
                    dp[i] += dp[j];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i].size() == words[j].size()) {
                    dp[j
    }
};
// @lc code=end

