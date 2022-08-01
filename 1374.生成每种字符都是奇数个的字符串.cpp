/*
 * @lc app=leetcode.cn id=1374 lang=cpp
 *
 * [1374] 生成每种字符都是奇数个的字符串
 */

// @lc code=start
class Solution
{
public:
    string generateTheString(int n)
    {
        if (n % 2 == 1)
        {
            return string(n, 'a');
        }
        return string(n - 1, 'a') + 'b';
    }
};

// @lc code=end
