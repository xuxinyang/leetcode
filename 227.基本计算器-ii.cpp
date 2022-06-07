/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int sign = 1;
        int num = 0;
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] == '+') {
                sign = 1;
            } else if (s[i] == '-') {
                sign = -1;
            } else if (s[i] == '(') {
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
            } else if (s[i] == ')') {
                res *= stk.top();
                stk.pop();
                res += stk.top();
                stk.pop();
            } else {
                num = num * 10 + s[i] - '0';
                if (i == s.size() - 1 || s[i+1] == ' ') {
                    res += sign * num;
                    num = 0;
                }
            }
        }
        return res;
    }
};
// @lc code=end

