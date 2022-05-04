/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

// @lc code=start
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            q.emplace(i);
        }
        while (q.size() > 1) {
            for (int i = 1; i < k; i++) {
                q.emplace(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};
// @lc code=end

