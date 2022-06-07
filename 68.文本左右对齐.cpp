/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

// @lc code=start
class Solution {
    // 返回长度为n的由空格组成的字符串
    string blank(int n)
    {
        return string(n, ' ');
    }
    // 通过字符串进行拼接单词
    string join(vector<string> &words, int left, int right, string sep)
    {
        string s = words[left];
        for (int i = left + 1; i < right; i++)
        {
            s += sep + words[i];
        }
        return s;
    }
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        int right = 0, n = words.size();
        while (true)
        {
            int left = right;
            int sumLen = 0;
            while (right < n && sumLen + words[right].length() + right - left <= maxWidth)
            {
                sumLen += words[right++].length();
            }
            if (right == n)
            {
                string s = join(words, left, n, " ");
                ans.emplace_back(s + blank(maxWidth - s.length()));
                return ans;
            }
            int numWords = right - left;
            int numSpaces = maxWidth - sumLen;
            if (numWords == 1)
            {
                ans.emplace_back(words[left] + blank(numSpaces));
                continue;
            }
            int avgSpaces = numSpaces / (numWords - 1);
            int extraSpaces = numSpaces % (numWords - 1);
            string s1 = join(words, left, left+extraSpaces+1, blank(avgSpaces+1));
            string s2 = join(words, left+extraSpaces + 1, right, blank(avgSpaces));
            ans.emplace_back(s1+blank(avgSpaces)+s2);
        }
    }
};
// @lc code=end

