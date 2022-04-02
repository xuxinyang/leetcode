/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        int res = n / 2;
        unordered_set<int> s(candyType.begin(), candyType.end());
        return min(res, (int)s.size());
    }
};
// @lc code=end

