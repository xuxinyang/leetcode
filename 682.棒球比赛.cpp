/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        stack<int> s;
        for (auto& op : ops) {
            if (op == "C") {
                s.pop();
            } else if (op == "D") {
                s.push(s.top() * 2);
            } else if (op == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.push(a);
                s.push(a + b);
            } else {
                s.push(stoi(op));
            }
        }
        while (!s.empty()) {
            res += s.top();
            s.pop();
        }
        return res;
    }
};
// @lc code=end

