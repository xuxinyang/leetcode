/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> stk;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        stk.push_back(0);
        dfs(graph, 0, graph.size() - 1);
        return ans;
    }
    void dfs(vector<vector<int>>& graph, int cur, int target) {
        if (cur == target) {
            ans.push_back(stk);
            return;
        }
        for (int i = 0; i < graph[cur].size(); i++) {
            stk.push_back(graph[cur][i]);
            dfs(graph, graph[cur][i], target);
            stk.pop_back();
        }
    }
};
// @lc code=end

