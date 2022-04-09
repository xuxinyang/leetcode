/*
 * @lc app=leetcode.cn id=745 lang=cpp
 *
 * [745] 前缀和后缀搜索
 */

// @lc code=start
class WordFilter {
public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        if (n == 0) return;
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
                    dp[j]
    }
    
    int f(string prefix, string suffix) {
        int n = dp.size();
        int l = prefix.size(), r = suffix.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (words[i].size() < l) continue;
            if (words[i].size() > r) continue;
            if (words[i].substr(0, l) != prefix) continue;
            if (words[i].substr(words[i].size() - r) != suffix) continue;
            res += dp[i];
        }
        return res;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
// @lc code=end

