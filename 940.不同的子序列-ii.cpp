/*
 * @lc app=leetcode.cn id=940 lang=cpp
 *
 * [940] 不同的子序列 II
 */

// @lc code=start
class Solution {
private:
    static constexpr int mod = 1e9+7;
public:
    int distinctSubseqII(string s) {
        vector<int> preCount(26, 0);
        int n = s.size();
        int curAns = 1;
        for (int i = 0; i < n; i++) {
            int newCount = curAns;
            curAns = ((curAns + newCount) % mod - preCount[s[i] - 'a'] % mod + mod) % mod;
            preCount[s[i] - 'a'] = newCount;
        }
        return curAns - 1;
    }
};
// @lc code=end

