/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c) return mat;
        vector<vector<int>> res;
        vector<int> tmp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                tmp.push_back(mat[i][j]);
            }
        }
        vector<int> tmp2;
        for (int i = 0; i < r * c; ++i) {
            tmp2.push_back(tmp[i]);
            if (i % c == c - 1) {
                res.push_back(tmp2);
                tmp2.clear();
            }
        }
        return res;
    }
};
// @lc code=end

