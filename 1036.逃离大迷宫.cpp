/*
 * @lc app=leetcode.cn id=1036 lang=cpp
 *
 * [1036] 逃离大迷宫
 */

// @lc code=start
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int m = blocked.size();
        int n = blocked[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<vector<int>> q;
        q.push(source);
        visited[source[0]][source[1]] = 1;
        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            if (cur[0] == target[0] && cur[1] == target[1]) {
                return true;
            }
            for (int i = 0; i < 4; i++) {
                int x = cur[0] + dx[i];
                int y = cur[1] + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && !isBlocked(blocked, x, y)) {
                    visited[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
        return false;
    }
private:
    bool isBlocked(vector<vector<int>>& blocked, int x, int y) {
        for (auto& b : blocked) {
            if (b[0] == x && b[1] == y) {
                return true;
            }
        }
        return false;
    }
    const vector<int> dx = {0, 1, 0, -1};
    const vector<int> dy = {1, 0, -1, 0};
};
// @lc code=end

