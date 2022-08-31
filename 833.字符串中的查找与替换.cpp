/*
 * @lc app=leetcode.cn id=833 lang=cpp
 *
 * [833] 字符串中的查找与替换
 */

// @lc code=start

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        stringstream ss;
        int mark[s.size()];
        memset(mark, 0, sizeof(mark));
        for (int i = 0; i < indices.size(); ++i)
        {
            if (s.substr(indices[i], sources[i].size()) == sources[i])
            {
                mark[indices[i]] = i+1;
            }
        }
        int n = s.size();
        int i = 0;
        while (i < n)
        {
            if (mark[i] == 0)
            {
                ss << s[i];
                ++i;
            }
            else
            {
                ss << targets[mark[i]-1];
                i += sources[mark[i]-1].size();
            }
        }
        return ss.str();
    }
};
// @lc code=end

