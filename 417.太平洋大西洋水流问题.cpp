/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
public:
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        if (heights.empty()) {
            return res;
        }
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        for (int i = 0; i < n; ++i) {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, m - 1, i);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int i, int j) {
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()) {
            return;
        }
        if (visited[i][j] == 1) {
            return;
        }
        visited[i][j] = 1;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size()) {
                continue;
            }
            if (heights[x][y] >= heights[i][j]) {
                dfs(heights, visited, x, y);
            }
        }
    }
};
// @lc code=end

