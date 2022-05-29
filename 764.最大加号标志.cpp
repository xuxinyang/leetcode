/*
 * @lc app=leetcode.cn id=764 lang=cpp
 *
 * [764] 最大加号标志
 */

// @lc code=start
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        for (auto mine : mines) {
            grid[mine[0]][mine[1]] = -1;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int left = 0, right = 0, up = 0, down = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == -1) {
                    left = 0;
                    right = 0;
                    up = 0;
                    down = 0;
                } else {
                    if (grid[i][j] == 0) {
                        left = j + 1;
                        right = n - j;
                        up = i + 1;
                        down = n - i;
                    }
                    grid[i][j] = min(left, min(right, min(up, down)));
                }
            }
            res = max(res, min(left, min(right, min(up, down))));
        }
        for (int j = 0; j < n; ++j) {
            int left = 0, right = 0, up = 0, down = 0;
            for (int i = 0; i < n; ++i) {
                if (grid[i][j] == -1) {
                    left = 0;
                    right = 0;
                    up = 0;
                    down = 0;
                } else {
                    if (grid[i][j] == 0) {
                        left = j + 1;
                        right = n - j;
                        up = i + 1;
                        down = n - i;
                    }
                    grid[i][j] = min(left, min(right, min(up, down)));
                }
            }
            res = max(res, min(left, min(right, min(up, down))));
        }
        return res;
    }
};
// @lc code=end

