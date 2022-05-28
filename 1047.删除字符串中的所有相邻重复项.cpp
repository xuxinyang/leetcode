/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (auto c : s) {
            if (st.empty() || st.top() != c) {
                st.emplace(c);
            } else {
                st.pop();
            }
        }
        string res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
    }
};
// @lc code=end

