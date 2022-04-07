/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */

// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        if (s == goal) return true;
        for (int i = 1; i < s.size(); ++i) {
            if (s.substr(i) + s.substr(0, i) == goal) return true;
        }
        return false;
    }
};
// @lc code=end

