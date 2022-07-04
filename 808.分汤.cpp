/*
 * @lc app=leetcode.cn id=808 lang=cpp
 *
 * [808] 分汤
 */

// @lc code=start
class Solution {
public:
    double soupServings(int N) {
        if(N == 0) return 0.5;
        if(N >= 25 * 500) return 1.0;//根据本算法，N超过该值时，概率为1e-6
        int near[4][2]={{4,0},{3,1},{2,2},{1,3}};
        N = N/25 + (N%25 ? 1 : 0);
        vector<vector<double>> dp(N+1, vector<double>(N+1));

        dp[0][0] = 0.5;
        for(int i=1;i<=N;i++){
            dp[i][0] = 0;
            dp[0][i] = 1.0;
        }

        int x,y;
        for(int i = 1;i<=N;i++){
            for(int j=1;j<=N;j++){
                for(int k=0;k<4;k++){
                    x = max(i-near[k][0], 0);
                    y = max(j-near[k][1], 0);
                    dp[i][j] += dp[x][y];
                }
                dp[i][j] = dp[i][j] * 0.25;
            }
        }
        return dp[N][N];
    }
};
// @lc code=end

