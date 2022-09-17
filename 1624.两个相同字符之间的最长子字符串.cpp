/*
 * @lc app=leetcode.cn id=1624 lang=cpp
 *
 * [1624] 两个相同字符之间的最长子字符串
 */

// @lc code=start
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> v[26];
        for (int i = 0; i < s.length(); i++)
        {
            v[s[i]-'a'].push_back(i);
        }
        int maxx = 0, flag = 0;
        for (int i = 0; i < 26; i++)
        {
            if (v[i].size() > 1)
            {
                flag =1;
                maxx = max(maxx, v[i][int(v[i].size())-1]-v[i][0] - 1);
            }
        }
        if (flag == 0) return -1;
        return maxx;
    }
};
// @lc code=end

