/*
 * @lc app=leetcode.cn id=1105 lang=cpp
 *
 * [1105] 填充书架
 */

// @lc code=start
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        int dp[n + 1];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int tmp_width = 0, j = i, h = 0;
            while (j > 0)
            {
                tmp_width += books[j-1][0];
                if (tmp_width > shelfWidth) break;
                h = max(h, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + h);
                j -= 1;
            }
        }
        return dp[n];
    }
};
// @lc code=end

