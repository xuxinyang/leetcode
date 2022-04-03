/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;
        int n = s.size(), m = words[0].size(), k = words.size();
        unordered_map<string, int> dict;
        for (string word: words)
        {
            ++dict[word];
        }
        for (int i = 0; i < m; ++i)
        {
            int left = i, count = 0;
            unordered_map<string, int> tdict = dict;
            for (int j = i; j <= n - m; j += m)
            {
                string word = s.substr(j, m);
                if (tdict.count(word) == 0)
                {
                    tdict = dict;
                    count = 0;
                    left = j + m;
                }
                else
                {
                    --tdict[word];
                    if (tdict[word] >= 0) ++count;
                    else
                    {
                        ++tdict[word];
                        --count;
                    }
                    if (count == k)
                    {
                        res.push_back(left);
                        ++left;
                        ++count;
                        tdict = dict;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

