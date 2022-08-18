/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution
{
public:
    vector<int> direction{-1, 0, 1, 0, -1};

    int shortestBridge(vector<vector<int>> &A)
    {
        int m = A.size(), n = A[0].size();
        queue<pair<int, int>> points;
        //使用dfs寻找第一个岛屿，并把1变成2
        bool flipped = false;
        for (int i(0); i < m; ++i)
        {
            if (flipped)
                break;
            for (int j(0); j < n; ++j)
            {
                if (A[i][j] == 1)
                {
                    dfs(points, A, m, n, i, j);
                    flipped = true;
                    break;
                }
            }
        }
        // bfs寻找第二个岛屿，把过程中的0变成2
        int x, y;
        int level = 0;
        while (!points.empty())
        {
            ++level;
            int n_points = points.size();
            while (n_points--)
            {
                auto [r, c] = points.front();
                points.pop();
                for (int k(0); k < 4; ++k)
                {
                    x = r + direction[k], y = c + direction[k + 1];
                    if (x >= 0 && y >= 0 && x < m && y < n)
                    {
                        if (A[x][y] == 2)
                            continue;
                        if (A[x][y] == 1)
                            return level;
                        points.push({x, y});
                        A[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }

    void dfs(queue<pair<int, int>> &points, vector<vector<int>> &grid, int m, int n,
             int i, int j)
    {
        //先考察方向问题
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2)
            return;
        //再考虑别的推出方式
        if (grid[i][j] == 0)
        {
            points.push({i, j});
            return;
        }
        grid[i][j] = 2;
        dfs(points, grid, m, n, i - 1, j);
        dfs(points, grid, m, n, i + 1, j);
        dfs(points, grid, m, n, i, j - 1);
        dfs(points, grid, m, n, i, j + 1);
    }
};

// @lc code=end
