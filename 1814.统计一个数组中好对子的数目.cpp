/*
 * @lc app=leetcode.cn id=1814 lang=cpp
 *
 * [1814] 统计一个数组中好对子的数目
 */

// @lc code=start
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9+7;
        int res = 0;
        unordered_map<int, int> h;
        for (int i: nums) {
            int temp = i, j = 0;
            while (temp)
            {
                j = j * 10 + temp % 10;
                temp /= 10;
            }
            res = (res + h[i-j]) % MOD;
            h[i-j] ++;
        }
        return res;
    }
};
// @lc code=end

