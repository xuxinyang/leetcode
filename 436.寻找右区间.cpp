/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> um;
        for (int i = 0; i < n; ++i) {  //记录下每个区间原始位置
            um[intervals[i][0]] = i;
        }
        sort(intervals.begin(), intervals.end(), [&](const auto& v1, const auto& v2){  //按区间起点升序排序
            return v1[0] < v2[0];
        });
        for (int i = 0; i < n; ++i) {  //二分查找
            int target = intervals[i][1];
            int lo = i, hi = n - 1;
            while (lo <= hi) {
                int mi = lo + ((hi - lo) >> 1);
                if (intervals[mi][0] >= target) {
                    ans[um[intervals[i][0]]] = um[intervals[mi][0]];
                    hi = mi - 1;
                } else {
                    lo = mi + 1;
                }
            }
        }
        return ans;
    }

};
// @lc code=end

