/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

// @lc code=start
class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1) return 1;
        return (k + findTheWinner(n - 1, k) - 1) % n + 1;
    }
};
// @lc code=end

