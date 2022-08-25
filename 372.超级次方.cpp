/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */

// @lc code=start
class Solution {
    const int mod = 1337;
    int qpow(int a, int b)
    {
        int res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = (long) res * a % mod;
            }
            a = (long) a * a % mod;
            b >>= 1;
        }
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        for (int i = b.size() - 1; i >= 0; i--)
        {
            ans = (long) ans * qpow(a, b[i]) % mod;
            a = qpow(a, 10);
        }
        return ans;
    }
};
// @lc code=end

