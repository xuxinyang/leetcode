/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @lc code=start
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> timesMap;
        for (vector<int>& vec : wall) {
            int sum = 0;
            for (int i = 0; i < vec.size() - 1; ++i) {
                sum += vec[i];
                timesMap[sum]++;
            }
        }
        int result = 0;
        for (auto& a : timesMap)
            result = max(result, a.second);
        return wall.size() - result;
    }
};
// @lc code=end

