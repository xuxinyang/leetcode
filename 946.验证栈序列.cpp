/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int idx = 0;
        for (int i = 0; i < pushed.size(); i++) {
            st.emplace(pushed[i]);
            while (!st.empty() && st.top() == popped[idx]) {
                st.pop();
                idx++;
            }
        }
        return st.empty();
    }
};
// @lc code=end

