/*
 * @lc app=leetcode.cn id=828 lang=cpp
 *
 * [828] 统计子串中的唯一字符
 */

// @lc code=start
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

