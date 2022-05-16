/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) {
            return n;
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> m;
            int dup = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dup++;
                    continue;
                }
                double k = 0;
                if (points[i][0] == points[j][0]) {
                    k = INT_MAX;
                } else {
                    k = (points[i][1] - points[j][1]) * 1.0 / (points[i][0] - points[j][0]);
                }
                m[k]++;
            }
            ret = max(ret, dup);
            for (auto it = m.begin(); it != m.end(); it++) {
                ret = max(ret, it->second + dup);
            }
        }
        return ret;
    }
};
// @lc code=end

