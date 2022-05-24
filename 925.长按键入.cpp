/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size(), m = typed.size();
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (name[i] == typed[j]) {
                ++i;
                ++j;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                ++j;
            } else {
                return false;
            }
        }
        while (j < m && typed[j] == name[n-1]) {
            ++j;
        }
        return i == n && j == m;
    }
};
// @lc code=end

