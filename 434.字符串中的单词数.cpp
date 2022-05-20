/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        bool flag = false;
        for (auto c : s) {
            if (c == ' ') {
                if (flag) {
                    ans++;
                }
                flag = false;
            } else {
                flag = true;
            }
        }
        if (flag) {
            ans++;
        }
        return ans;
    }
};
// @lc code=end

