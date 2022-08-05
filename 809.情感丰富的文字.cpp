/*
 * @lc app=leetcode.cn id=809 lang=cpp
 *
 * [809] 情感丰富的文字
 */

// @lc code=start
class Solution
{
public:
    int expressiveWords(string s, vector<string> &words)
    {
        int ans = 0;
        for (string &w : words)
            ans += check(s, w);
        return ans;
    }

    bool check(string &s, string &w)
    {
        if (w.size() > s.size() || s[0] != w[0])
            return false;
        int i = 0, j = 0, len1 = w.size(), len2 = s.size();
        while (j < len2)
        {
            if (w[i] == s[j])
                i++, j++;
            else
            {
                int k = j, cnt = 1;
                while (k > 0 && s[k] == s[k - 1])
                    k--, cnt++;
                k = j;
                while (k < len2 - 1 && s[k] == s[k + 1])
                    k++, cnt++;
                if (cnt < 3)
                    return false;
                j = k + 1;
                if (w[i] != s[j])
                    return false;
            }
        }
        return i == len1;
    }
};
// @lc code=end
