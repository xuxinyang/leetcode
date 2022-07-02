/*
 * @lc app=leetcode.cn id=1840 lang=cpp
 *
 * [1840] 最高建筑高度
 */

// @lc code=start
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<restrictions.size();i++){
            int x1 = restrictions[i][0];
            int x2 = restrictions[i][1];
            int y = restrictions[i][2];
            dp[x1][x2] = max(dp[x1][x2],y);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                for(int k=i+1;k<n;k++){
                    dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,dp[0][i]);
        }
        return ans;
    }
};
// @lc code=end

