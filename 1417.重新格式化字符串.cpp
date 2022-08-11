/*
 * @lc app=leetcode.cn id=1417 lang=cpp
 *
 * [1417] 重新格式化字符串
 */

// @lc code=start
class Solution
{
public:
    string reformat(string s)
    {
        string s1 = "", s2 = "", s3 = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                s1 += s[i];
            else
                s2 += s[i];
        }
        if (abs(int(s1.size()) - int(s2.size())) > 1)
            return "";
        if (s1.size() > s2.size())
        {
            for (int i = 0; i < s2.size(); i++)
            {
                s3 += s1[i], s3 += s2[i];
            }
            s3 += s1[s1.size() - 1];
        }
        else if (s1.size() == s2.size())
        {
            for (int i = 0; i < s2.size(); i++)
            {
                s3 += s1[i], s3 += s2[i];
            }
        }
        else
        {
            for (int i = 0; i < s1.size(); i++)
            {
                s3 += s2[i], s3 += s1[i];
            }
            s3 += s2[s2.size() - 1];
        }
        return s3;
    }
};
// @lc code=end
