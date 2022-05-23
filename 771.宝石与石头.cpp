/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for (int i = 0; i < stones.size(); ++i) {
            if (jewels.find(stones[i]) != string::npos) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

