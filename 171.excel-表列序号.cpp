/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long res = 0;
        for (char c : columnTitle) {
            res = res * 26 + c - 'A' + 1;
        }
        return res;
    }
};
// @lc code=end

