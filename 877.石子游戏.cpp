/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int sum_Alice, sum_Bob, i = 0, j = piles.size() - 1;
        while (i < j)
        {
            if (piles[i] > piles[j]) {
                sum_Alice += piles[i], i++;
            } else {
                sum_Alice += piles[j], j--;
            }
            if (piles[i] > piles[j]) {
                sum_Bob += piles[i], i++;
            } else {
                sum_Bob += piles[j], j--;
            }
        }
        return sum_Alice > sum_Bob;
    }
};
// @lc code=end

