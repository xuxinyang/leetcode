/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
const int MO = 1e9 + 7;
using LL = long long;
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> l(n);
        vector<int> r(n);
        stack<int> stk;
        for (int i = 0; i < n; ++i)
        {
            while (stk.size() && arr[stk.top()] > arr[i])
            {
                stk.pop();
            }
            l[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i)
        {
            while (stk.size() && arr[stk.top()] >= arr[i])
            {
                stk.pop();
            }
            r[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = (ans + 1LL * arr[i] * ((r[i] - i) * (i - l[i]) % MO) % MO) % MO;
        }
        return ans;
    }
};
// @lc code=end
