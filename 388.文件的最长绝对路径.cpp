/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */

// @lc code=start
class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int pos = 0;
        int ans = 0;
        stack<int> st;

        while (pos < n) {
            // 检测当前文件深度
            int depth = 1;
            while (pos < n && input[pos] == '\t') {
                depth++;
                pos++;
            }
            // 统计当前文件名的长度
            int len = 0;
            bool isFile = false;
            while (pos < n && input[pos] != '\n') {
                if (input[pos] == '.') {
                    isFile = true;
                }
                len++;
                pos++;
            }
            // 跳过换行符
            pos++;
            while (st.size() >= depth) {
                st.pop();
            }
            if (!st.empty()) {
                len += st.top() + 1;
            }
            if (isFile) {
                ans = max(ans, len);
            } else
                st.emplace(len);
        }
        return ans;
    }
};
// @lc code=end

