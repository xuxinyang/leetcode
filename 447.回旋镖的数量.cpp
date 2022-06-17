/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> map;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int d = dist(points[i], points[j]);
                map[d]++;
            }
            for (auto it = map.begin(); it != map.end(); it++) {
                res += it->second * (it->second - 1);
            }
        }
        return res;
    }
    int dist(vector<int>& a, vector<int>& b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
};
// @lc code=end

