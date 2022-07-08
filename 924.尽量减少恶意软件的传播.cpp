/*
 * @lc app=leetcode.cn id=924 lang=cpp
 *
 * [924] 尽量减少恶意软件的传播
 */

// @lc code=start
class DJset {
public:     
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DJset(int n): parent(n), rank(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;   
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            if (rank[rx] < rank[ry]) swap(rx, ry);
            parent[ry] = rx;
            size[rx] += size[ry];
            size[ry] = 0;
            if (rank[rx] == rank[ry]) rank[rx] += 1;
        }
    }
};

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        sort(initial.begin(), initial.end());
        int minM = n;         // 记录最少感染节点数
        int idx = initial[0]; // 记录产生最少感染节点数的 删除节点

        // 计算在删除 e 节点的条件下，有多少个节点被感染
        for (auto& e : initial) {
            int M = 0;
            DJset ds(n);
            // 重构并查集
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (graph[i][j] == 1) ds.merge(i, j);
                }
            }
            // 计算重构之后的感染节点数
            unordered_set<int> seen;
            for (auto& i : initial) {
                if (i == e) continue;
                int ri = ds.find(i);
                if (seen.count(ri)) continue;
                seen.insert(ri);
                M += ds.size[ri];
            }
            if (M < minM) {
                minM = M;
                idx = e;
            }
        }

        return idx;
    }
};

// @lc code=end

