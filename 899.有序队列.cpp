/*
 * @lc app=leetcode.cn id=899 lang=cpp
 *
 * [899] 有序队列
 */

// @lc code=start
class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        if (k == 1)
        {
            string smallest = s;
            int n = s.size();
            for (int i = 1; i < n; i++)
            {
                char c = s[0];
                s = s.substr(1);
                s.push_back(c);
                if (s < smallest)
                {
                    smallest = s;
                }
            }
            return smallest;
        }
        else
        {
            sort(s.begin(), s.end());
            return s;
        }
    }
};
// @lc code=end
