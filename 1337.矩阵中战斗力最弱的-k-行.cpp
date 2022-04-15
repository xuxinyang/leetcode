/*
 * @lc app=leetcode.cn id=1337 lang=cpp
 *
 * [1337] 矩阵中战斗力最弱的 K 行
 */

// @lc code=start
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        int n = mat.size();
        int m = mat[0].size();
        vector<int> sum(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum[i] += mat[i][j];
            }
        }
        // 从小到大加入优先队列
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({sum[i], i});
        }
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

