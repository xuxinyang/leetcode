/*
 * @lc app=leetcode.cn id=869 lang=cpp
 *
 * [869] 重新排序得到 2 的幂
 */

// @lc code=start
string countDigits(int n)
{
    string cnt(10, 0);
    while (n)
    {
        ++cnt[n % 10];
        n /= 10;
    }
    return cnt;
}

unordered_set<string> powerOf2Digits;

int init = []()
{
    for (int n = 1; n <= 1e9; n <<= 1)
    {
        powerOf2Digits.insert(countDigits(n));
    }
    return 0;
}();

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        return powerOf2Digits.count(countDigits(n));
    }
};
// @lc code=end
