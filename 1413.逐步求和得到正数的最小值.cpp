/*
 * @lc app=leetcode.cn id=1413 lang=cpp
 *
 * [1413] 逐步求和得到正数的最小值
 */

// @lc code=start
class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        int sum = 0, minSum = 0;
        for (int num : nums)
        {
            sum += num;
            minSum = min(minSum, sum);
        }
        return 1 - minSum;
    }
};
// @lc code=end
