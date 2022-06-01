/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 */

// @lc code=start
class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8));
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            days[1] = 29;
        }
        int res = 0;
        for (int i = 0; i < month - 1; i++) {
            res += days[i];
        }
        return res + day;
    }
};
// @lc code=end

