/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
class Solution {
public:
    int find(int x, vector<int> &fa) {
        return fa[x] < 0 ? x : fa[x] = find(fa[x], fa);
    }
    void merge(int x, int y, vector<int> &fa) {
        x = find(x, fa);
        y = find(y, fa);
        if (x == y) {
            return;
        }
        if (fa[x] < fa[y]) {
            swap(x, y);
        }
        fa[x] += fa[y];
        fa[y] = x;
    }
    bool isconnect(int x, int y, vector<int> &fa) {
        x = find(x, fa);
        y = find(y, fa);
        return x == y;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> fa(n+1, -1);
        vector<vector<int>> g(n+1);
        for (auto &p: dislikes) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < g[i].size(); j++) {
                merge(g[i][0], g[i][j], fa);
                if (isconnect(i, g[i][j], fa)) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

