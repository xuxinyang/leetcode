/*
 * @lc app=leetcode.cn id=932 lang=cpp
 *
 * [932] 漂亮数组
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, vector<int> > mp;
    vector<int> beautifulArray(int n)
    {
        return f(n);
    }
    vector<int> f(int n)
    {
        vector<int> res(n, 0);
        int t = 0;
        if (mp.find(n) != mp.end()) {
            return mp[n];
        }
        if (n != 1)
        {
            for (auto i: f((n+1)/2))
            {
                res[t++] = 2 * i - 1;
            }
            for (auto i: f(n/2))
            {
                res[t++] = 2 * i;
            }
        }
        else
        {
            res[0] = 1;
        }
        mp[n] = res;
        return res;
    }
};
// @lc code=end
