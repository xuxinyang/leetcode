/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int row = 0, col = 0, dir = 0;
        int num = 1;
        while (num <= n * n) {
            res[row][col] = num++;
            switch (dir) {
                case 0:
                    if (col == n - 1 || res[row][col + 1] != 0) {
                        dir = (dir + 1) % 4;
                        row++;
                    } else {
                        col++;
                    }
                    break;
                case 1:
                    if (row == n - 1 || res[row + 1][col] != 0) {
                        dir = (dir + 1) % 4;
                        col--;
                    } else {
                        row++;
                    }
                    break;
                case 2:
                    if (col == 0 || res[row][col - 1] != 0) {
                        dir = (dir + 1) % 4;
                        row--;
                    } else {
                        col--;
                    }
                    break;
                case 3:
                    if (row == 0 || res[row - 1][col] != 0) {
                        dir = (dir + 1) % 4;
                        col++;
                    } else {
                        row--;
                    }
                    break;
            }
        }
        return res;
    }
};
// @lc code=end

