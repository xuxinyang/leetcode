/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        return (int)((sqrt((long long) 8 * n + 1) - 1) / 2);

    }
};
// @lc code=end

