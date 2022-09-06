/*
 * @lc app=leetcode.cn id=828 lang=cpp
 *
 * [828] 统计子串中的唯一字符
 */

// @lc code=start
/**
 * @brief 
 * 对于下标为 i 的字符 ci ，当它在某个子字符串中仅出现一次时，它会对这个子字符串统计唯一字符时有贡献。只需对每个字符，计算有多少子字符串仅包含该字符一次即可。对于 ci， 记同字符上一次出现的位置为 cj，下一次出现的位置为 ck ，那么这样的子字符串就一共有(ci−cj)×(ck−ci) 种，即子字符串的起始位置有 cj（不含）到 ci（含）之间这 (ci−cj) 种可能，到结束位置有(ck−ci) 种可能。可以预处理 s，将相同字符的下标放入数组中，方便计算。最后对所有字符进行这种计算即可。
 */
class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int> > index;
        for (int i = 0; i < s.size(); i++)
        {
            index[s[i]].emplace_back(i);
        }
        int res = 0;
        for (auto &&[_, arr]: index) {
            arr.insert(arr.begin(), -1);
            arr.emplace_back(s.size());
            for (int i = 1; i < arr.size() - 1; i++) {
                res += (arr[i]-arr[i-1]) * (arr[i+1] - arr[i]);
            }
        }
        return res;
    }
};
// @lc code=end

