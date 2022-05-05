/*
 * @lc app=leetcode.cn id=1901 lang=cpp
 *
 * [1901] 找出顶峰元素 II
 */

// @lc code=start
class Solution {
public:
    int m;
    int maxValIdxInRow(vector<vector<int>>& mat, int row) {
        return static_cast<int>(max_element(mat[row].begin(), mat[row].end()) - mat[row].begin()) ;
    }
    int check(vector<vector<int>>& mat, int row) {
        int col = maxValIdxInRow(mat, row);
        if (row<m-1 && mat[row][col] < mat[row+1][col]) {
            return 1; // 局部单调增
        } else if (row>0 && mat[row][col] < mat[row-1][col]) {
            return -1; // 局部单调减
        } else {
            return 0; // 找到峰值
        }
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        m = (int)mat.size();
        int up = -1, down = m; // row ∈ [0,m-1]
        while (up +1 != down) {
            int mid = up+(down-up)/2;
            int res = check(mat, mid);
            if (res == 0) { // 找到峰值，返回结果
                return {mid, maxValIdxInRow(mat, mid)};
            } else if (res == 1) {  // 局部单调增
                up = mid; // 移动 up 指针缩小查找区间进行夹逼
            } else { // 局部单调减
                down = mid; // 移动 down 指针缩小查找区间进行夹逼
            }
        }
        return {-1,-1};
    }
};

// @lc code=end

