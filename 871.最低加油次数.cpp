/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */

// @lc code=start
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int n = stations.size(), ans = 0, cur = startFuel, i = 0;
        while (cur < target) {
            while (i < n && stations[i][0] <= cur) {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty()) {
                return -1;
            }
            cur += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};
// @lc code=end

