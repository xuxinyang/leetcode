/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

// @lc code=start
class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 1;
        for (int i = 2; i <= n; ++i) {
            winner = (k + winner - 1) % i + 1;
        }
        return winner;
    }
};
// @lc code=end

