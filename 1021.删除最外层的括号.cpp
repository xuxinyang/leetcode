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
        stack<char> st;
        for (auto c : s) {
            if (c == ')') {
                st.pop();
            }
            if (!st.empty()) {
                res.push_back(c);
            }
            if (c == '(') {
                st.emplace(c);
            }
        }
        return res;
    }
};
// @lc code=end

