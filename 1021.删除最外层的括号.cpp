/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int n = s.size();
        int left = 0;
        int right = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                res += s.substr(i + 1, left - 1);
                left = 0;
                right = 0;
            }
        }
        return res;
    }
};
// @lc code=end

