/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) {
            return 0;
        }
        vector<string> visited;
        queue<string> q;
        q.push(start);
        visited.push_back(start);
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();
                for (int j = 0; j < bank.size(); j++) {
                    if (isOneDifference(cur, bank[j])) {
                        if (bank[j] == end) {
                            return step + 1;
                        }
                        if (find(visited.begin(), visited.end(), bank[j]) == visited.end()) {
                            q.push(bank[j]);
                            visited.push_back(bank[j]);
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
private:
    bool isOneDifference(string s1, string s2) {
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff++;
            }
        }
        return diff == 1;
    }
};
// @lc code=end

