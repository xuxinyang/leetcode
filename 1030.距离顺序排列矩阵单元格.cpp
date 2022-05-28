/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> res;
        vector<int> tmp;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                tmp.push_back(i);
                tmp.push_back(j);
                res.push_back(tmp);
                tmp.clear();
            }
        }
        sort(res.begin(), res.end(), [rCenter, cCenter](vector<int>& a, vector<int>& b) {
            return abs(a[0] - rCenter) + abs(a[1] - cCenter) < abs(b[0] - rCenter) + abs(b[1] - cCenter);
        });
        return res;
    }
};
// @lc code=end

