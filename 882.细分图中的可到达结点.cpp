/*
 * @lc app=leetcode.cn id=882 lang=cpp
 *
 * [882] 细分图中的可到达结点
 */

// @lc code=start
#define p pair<int, int>
class Solution
{
public:
    int reachableNodes(vector<vector<int>> &edges, int m, int n)
    {
        vector<vector<p>> graph(n);
        for (vector<int> edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        map<int, int> dist;
        dist[0] = 0;
        for (int i = 1; i < n; i++)
            dist[i] = m + 1;
        map<p, int> used;
        int ans = 0;
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 0});
        while (!pq.empty())
        {
            p top = pq.top();
            pq.pop();
            int d = top.first, node = top.second;
            if (d > dist[node])
                continue;
            dist[node] = d;
            ans++;
            for (auto pair : graph[node])
            {
                int nei = pair.first;
                int weight = pair.second;
                used[{node, nei}] = min(weight, m - d);

                int d2 = d + weight + 1;
                if (d2 < min(dist[nei], m + 1))
                {
                    pq.push({d2, nei});
                    dist[nei] = d2;
                }
            }
        }
        for (vector<int> edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            ans += min(w, used[{u, v}] + used[{v, u}]);
        }
        return ans;
    }
};
// @lc code=end
