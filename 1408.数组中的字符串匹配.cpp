/*
 * @lc app=leetcode.cn id=1408 lang=cpp
 *
 * [1408] 数组中的字符串匹配
 */

// @lc code=start
class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words.size(); j++)
                if (i != j && words[j].find(words[i]) != string::npos)
                {
                    ans.push_back(words[i]);
                    break;
                }
        return ans;
    }
};
// @lc code=end
