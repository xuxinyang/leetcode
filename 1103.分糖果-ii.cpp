/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 *
 * [1103] 分糖果 II
 */

// @lc code=start
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> dp(num_people, 0);
        int i = 0;
        while (candies > 0) {
            dp[i % num_people] += min(candies, i + 1);
            candies -= i + 1;
            i++;
        }
        return dp;
    }
};
// @lc code=end

