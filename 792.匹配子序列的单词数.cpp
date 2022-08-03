/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */

// @lc code=start
class Solution
{
private:
    char *cursor[26][50001];
    int len[26];

public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        memset(len, 0, sizeof(len));
        for (int i = 0; i < words.size(); i++)
        {
            int c = words[i][0] - 'a';
            cursor[c][len[c]++] = &words[i][0];
        }
        int ans = 0;
        for (char c : s)
        {
            c -= 'a';
            int k = len[c];
            len[c] = 0;
            for (int i = 0; i < k; i++)
            {
                char *next = cursor[c][i] + 1;
                if (!*next)
                    ans++;
                else
                {
                    int d = *next - 'a';
                    cursor[d][len[d]++] = next;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
