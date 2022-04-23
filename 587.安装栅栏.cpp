/*
 * @lc app=leetcode.cn id=587 lang=cpp
 *
 * [587] 安装栅栏
 */

// @lc code=start
class Solution {
public:
    int cross(vector<int> &p, vector<int> &q, vector<int> &r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n <= 3) return trees;
        int leftMost = 0;
        for (int i = 1; i < n; i++) {
            if (trees[i][0] < trees[leftMost][0]) leftMost = i;
        }
        vector<vector<int>> res;
        vector<bool> visit(n, false);
        int p = leftMost;
        do {
            int q = (p + 1) % n;
            for (int r = 0; r < n; r++) {
                if (cross(trees[p], trees[q], trees[r]) < 0) {
                    q = r;
                }
            }
            for (int i = 0; i < n; i++) {
                if (visit[i] || i == p || i == q) continue;
                if (cross(trees[p], trees[q], trees[i]) == 0) {
                    visit[i] = true;
                    res.push_back(trees[i]);
                }
            }
            if (!visit[q]) {
                visit[q] = true;
                res.push_back(trees[q]);
            }
            p = q;
        } while (p != leftMost);
        return res;
    }
};
// @lc code=end

