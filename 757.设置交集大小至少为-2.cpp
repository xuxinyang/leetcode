/*
 * @lc app=leetcode.cn id=757 lang=cpp
 *
 * [757] 设置交集大小至少为2
 */

// @lc code=start
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        int i = 0;
        int j = 1;
        while (i < intervals.size() && j < intervals.size()) {
            if (intervals[i][1] < intervals[j][0]) {
                i++;
            } else if (intervals[i][1] > intervals[j][1]) {
                j++;
            } else {
                res += 2;
                i++;
                j++;
            }
        }
        return res;
    }
};
// @lc code=end

