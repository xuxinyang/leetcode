/*
 * @lc app=leetcode.cn id=1582 lang=cpp
 *
 * [1582] 二进制矩阵中的特殊位置
 */

// @lc code=start
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int res = 0;
        vector<int> row, col;
        for (int i = 0; i < mat.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < mat[0].size(); j++)
            {
                sum += mat[i][j];
            }
            row.push_back(sum);
        }
        for (int j = 0; j < mat[0].size(); j++)
        {
            int sum = 0;
            for (int i = 0; i < mat.size(); i++)
            {
                sum += mat[i][j];
            }
            col.push_back(sum);
        }
        for (int i = 0; i < row.size(); i++)
        {
            for (int j = 0; j < col.size(); j++)
            {
                if (row[i] == 1 && col[j] == 1 && mat[i][j] == 1) res++;
            }
        }
        return res;
    }
};
// @lc code=end

