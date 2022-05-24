/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */

// @lc code=start
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int n = s.size();
        int line = 1;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int w = widths[s[i] - 'a'];
            if (cur + w > 100) {
                ++line;
                cur = w;
            } else {
                cur += w;
            }
        }
        return {line, cur};
    }
};
// @lc code=end

