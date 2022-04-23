/*
 * @lc app=leetcode.cn id=464 lang=cpp
 *
 * [464] 我能赢吗
 */

// @lc code=start
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;
        if (maxChoosableInteger >= desiredTotal) return false;
        vector<int> dp(1 << maxChoosableInteger, 0);
        return canIWin(maxChoosableInteger, desiredTotal, dp);
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal, vector<int> &dp) {
        if (dp[desiredTotal] != 0) return dp[desiredTotal] == 1;
        for (int i = 1; i <= maxChoosableInteger; i++) {
            if (!(desiredTotal & (1 << i))) continue;
            if (canIWin(maxChoosableInteger, desiredTotal - i, dp)) {
                dp[desiredTotal] = 1;
                return true;
            }
        }
        dp[desiredTotal] = -1;
        return false;
    }
};
// @lc code=end

