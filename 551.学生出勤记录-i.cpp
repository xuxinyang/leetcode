/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        int a = 0,p = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'A') {
                a++;
            } else if (s[i] == 'L') {
                if (s[i+1] == 'L' && s[i+2] == 'L') {
                    return false;
                }
            }
            if (a > 1) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

