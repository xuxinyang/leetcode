/*
 * @lc app=leetcode.cn id=1139 lang=cpp
 *
 * [1139] 最大的以 1 为边界的正方形
 */

// @lc code=start
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        vector<vector<int> > rowSum(grid.size(), vector<int>(grid[0].size() + 1, 0));
        vector<vector<int> > colSum(grid.size() + 1, vector<int>(grid[0].size(), 0));
        // 计算前缀和
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[i + 1][j] = colSum[i][j] + grid[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = i; j < grid.size(); j++)
            {
                if ((j - i + 1) * (j - i + 1) <= res) continue;
                for (int k = 0; k < grid[0].size(); k++)
                {
                    if (grid[j][k] == 0) continue;
                    if ( k >= j - i && j - i != 0)
                    {
                        int target = (j - i + 1) * (j - i + 1) - max(j - i - 1, 0) * max(j - i - 1, 0);
                        int cur = rowSum[i][k + 1] - rowSum[i][k - j + i] +
                        rowSum[j][k + 1] - rowSum[j][k - j + i] +
                        colSum[j][k] - colSum[i + 1][k] +
                        colSum[j][k - j + i] - colSum[i + 1][k - j + i];
                        if (cur == target)
                            res = max(res, (j - i + 1) * (j - i + 1));
                    }
                    else
                    {
                        res = max(res, 1);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

