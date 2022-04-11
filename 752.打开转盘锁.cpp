/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000") || dead.count(target)) return -1;
        queue<string> q;
        q.push("0000");
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();
                if (cur == target) return step;
                if (dead.count(cur)) continue;
                for (int i = 0; i < 4; i++) {
                    string next = cur;
                    next[i] = (next[i] - '0' + 1) % 10 + '0';
                    if (next != cur) q.push(next);
                    next[i] = (next[i] - '0' - 1 + 10) % 10 + '0';
                    if (next != cur) q.push(next);
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end

