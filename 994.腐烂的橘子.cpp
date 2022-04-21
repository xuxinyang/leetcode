/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        // cout << m << " " << n << endl;
        if (grid[0].size() == 1 && grid.size()==1 && grid[0][0] == 0) return 0;
        vector<vector<int>> tes(m, vector<int>(n, 0));
        if (grid == tes) return 0;
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    fresh--;
                    q.push({x - 1, y});
                }
                if (x + 1 < m && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    fresh--;
                    q.push({x + 1, y});
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    fresh--;
                    q.push({x, y - 1});
                }
                if (y + 1 < n && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2;
                    fresh--;
                    q.push({x, y + 1});
                }
            }
            res++;
        }
        return fresh == 0 ? res - 1 : -1;
    }
};
// @lc code=end

