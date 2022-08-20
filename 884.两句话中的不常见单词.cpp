/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
 */

// @lc code=start
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> freq;

        auto insert = [&](const string &s)
        {
            stringstream ss(s);
            string word;
            while (ss >> word)
            {
                ++freq[word];
            }
        };

        insert(s1);
        insert(s2);

        vector<string> ans;
        for (const auto &[word, occ] : freq)
        {
            if (occ == 1)
            {
                ans.push_back(word);
            }
        }
        return ans;
    }
};
// @lc code=end
