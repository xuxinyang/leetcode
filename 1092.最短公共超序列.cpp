/*
 * @lc app=leetcode.cn id=1092 lang=cpp
 *
 * [1092] 最短公共超序列
 */

// @lc code=start
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string ans;
        int m = str1.size(), n = str2.size();
        //求公共子序列
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int i = m, j = n;
        //从后向前回溯加上字符串
        while(dp[i][j] > 0){
            if(str1[i - 1] == str2[j - 1]){
                //如果只在这里进行push_back这题就变成了求其中一个最长的重复子串的问题了，求超序列就是将不匹配的地方也求进去
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] >= dp[i][j-1]){
                    ans.push_back(str1[i - 1]);
                    i--;
                }
                else{
                    ans.push_back(str2[j - 1]);
                    j--;
                }
            }
        }
        //到这里字符串1的前i和字符串2的前j个字符完全不匹配,将这些字符全部加上即可,顺序随意
        while(i > 0 || j > 0){
            for(int k = i; k > 0; --k){
                ans.push_back(str1[k - 1]);
                i--;
            }
            for(int k = j; k > 0; --k){
                ans.push_back(str2[k - 1]);
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

