/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = 1;
        int end = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > end) {
                ans++;
                end = points[i][1];
            } else {
                end = min(end, points[i][1]);
            }
        }   
        return ans;
    }
};
// @lc code=end

