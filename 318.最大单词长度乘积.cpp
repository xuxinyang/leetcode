/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < words[i].size(); ++j) {
                dp[i] |= 1 << (words[i][j] - 'a');
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((dp[i] & dp[j]) == 0) {
                    res = max(res, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return res;
    }
};
// @lc code=end

