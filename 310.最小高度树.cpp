/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) leaves.push_back(i);
        }
        while (n > 2) {
            n -= leaves.size();
            vector<int> new_leaves;
            for (int i : leaves) {
                int j = adj[i][0];
                for (int k = 0; k < adj[j].size(); k++) {
                    if (adj[j][k] == i) {
                        adj[j].erase(adj[j].begin() + k);
                        break;
                    }
                }
                if (adj[j].size() == 1) new_leaves.push_back(j);
            }
            leaves = new_leaves;
        }
        return leaves;
    }
};
// @lc code=end

