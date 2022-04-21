/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
private:
    static constexpr int dx[4] = {0, 1, 0, -1};
    static constexpr int dy[4] = {1, 0, -1, 0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return mat;
        int m = mat[0].size();
        if (m == 0) return mat;
        vector<vector<int>> res(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = p.first + dx[i];
                int y = p.second + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]) {
                    vis[x][y] = 1;
                    res[x][y] = res[p.first][p.second] + 1;
                    q.push({x, y});
                }
            }
        }
        return res;
    }
};
// @lc code=end

