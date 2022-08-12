/*
 * @lc app=leetcode.cn id=1023 lang=cpp
 *
 * [1023] 驼峰式匹配
 */

// @lc code=start
class Solution
{
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> res;
        for (auto &query : queries)
        {
            res.push_back(match(query, pattern));
        }
        return res;
    }
    bool match(string &query, string &pattern)
    {
        int i = 0, j = 0;
        while (i < query.size())
        {
            if (query[i] == pattern[j] && j < pattern.size())
            {
                i++;
                j++;
            }
            else if (isupper(query[i]))
            {
                return false;
            }
            else
            {
                i++;
            }
        }
        return i == query.size() && j == pattern.size();
    }
};
// @lc code=end
