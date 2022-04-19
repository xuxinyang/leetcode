/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// @lc code=start
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res;
        vector<int> pos;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                pos.push_back(i);
            }
        }
        for (int i = 0; i < n; i++) {
            int minn = INT_MAX;
            for (int j = 0; j < pos.size(); j++) {
                minn = min(minn, abs(pos[j] - i));
            }
            res.push_back(minn);
        }
        return res;
    }
};
// @lc code=end

