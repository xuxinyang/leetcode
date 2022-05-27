/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n, false)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][j] = s1[i] == s2[j];
            }
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                for (int j = 0; j + len - 1 < n; j++) {
                    for (int k = 1; k < len; k++) {
                        dp[i][j][i + k - 1] = dp[i][j][i + k - 1] && dp[i + k][j][j + len - 1] || dp[i][j][i + len - 1] && dp[i + k][j + len - 1][j + k - 1];
                        dp[i][j][i + len - 1] = dp[i][j][i + len - 1] && dp[i][j + k][j + len - 1] || dp[i][j][i + k - 1] && dp[i + k][j][j + len - 1];
                    }
                }
            }
        }
        return dp[0][0][n - 1];
    }
};
// @lc code=end

