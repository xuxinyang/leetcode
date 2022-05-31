/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> m;
        int res = 0;
        for (vector<int> &domino : dominoes) {
            int a = min(domino[0], domino[1]);
            int b = max(domino[0], domino[1]);
            res += m[a * 10 + b];
            m[a * 10 + b]++;
        }
        return res;
    }
};
// @lc code=end

