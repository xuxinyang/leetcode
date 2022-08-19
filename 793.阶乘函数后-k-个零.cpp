/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后 K 个零
 */

// @lc code=startclass Solution {
class Solution
{
public:
    long long f(long long n)
    {
        long long ans = 0;
        for (long long i = n / 5; i > 0; i /= 5)
            ans += i;
        return ans;
    }

    int preimageSizeFZF(int K)
    {
        long long r = 1ll + 5ll * K;
        long long l = 4ll * K;
        while (l < r)
        {
            long long m = (l + r) / 2;
            if (f(m) < K)
                l = m + 1;
            else
                r = m;
        }
        return f(l) == K ? 5 : 0;
    }
};

// @lc code=end
