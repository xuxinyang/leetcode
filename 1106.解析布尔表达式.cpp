/*
 * @lc app=leetcode.cn id=1106 lang=cpp
 *
 * [1106] 解析布尔表达式
 */

// @lc code=start
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        for (char c : expression) {
            if (c == '(') {
                s.push(c);
            } else if (c == ')') {
                while (s.top() != '(') {
                    s.pop();
                }
                s.pop();
            } else if (c == '&') {
                while (!s.empty() && s.top() != '(') {
                    s.pop();
                }
            } else if (c == '|') {
                while (!s.empty() && s.top() != '(') {
                    s.pop();
                }
                s.push(c);
            } else if (c == '!') {
                s.push(c);
            } else {
                if (s.empty() || s.top() == '(') {
                    s.push(c);
                } else {
                    if (s.top() == '&') {
                        s.pop();
                        if (c == 't') {
                            s.push('f');
                        } else {
                            s.push('t');
                        }
                    } else {
                        s.pop();
                        if (c == 't') {
                            s.push('t');
                        } else {
                            s.push('f');
                        }
                    }
                }
            }
        }
        return s.top() == 't';
    }
};
// @lc code=end

