/*
 * @lc app=leetcode.cn id=962 lang=cpp
 *
 * [962] 最大宽度坡
 */

// @lc code=start
class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        stack<int> s;
        int res = 0;
        int n = nums.size();
        s.push(0);
        for (int i = 0; i < n; ++i)
        {
            if (s.empty() || nums[s.top()] > nums[i])
                s.push(i); // 严格单调递减栈
        }
        for (int j = n - 1; j >= res; --j) // 当然你要写成j >= 0也是可以AC的
        {
            while (s.size() && nums[s.top()] <= nums[j])
            {
                int pos = s.top();
                s.pop();
                res = max(res, j - pos);
            }
        }
        return res;
    }
};
// @lc code=end

