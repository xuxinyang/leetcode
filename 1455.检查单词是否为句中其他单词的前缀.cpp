/*
 * @lc app=leetcode.cn id=1455 lang=cpp
 *
 * [1455] 检查单词是否为句中其他单词的前缀
 */

// @lc code=start
class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        stringstream ss(sentence);
        string word;
        int i = 0;
        while (ss >> word)
        {
            if (word.length() < searchWord.length())
            {
                ++i;
                continue;
            }
            if (word.substr(0, searchWord.size()) == searchWord)
            {
                return i + 1;
            }
            ++i;
        }
        return -1;
    }
};
// @lc code=end
