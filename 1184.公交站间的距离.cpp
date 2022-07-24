/*
 * @lc app=leetcode.cn id=1184 lang=cpp
 *
 * [1184] 公交站间的距离
 */

// @lc code=start
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) swap(start, destination);
        return min(accumulate(distance.begin()+start, distance.begin()+destination, 0),
                    accumulate(distance.begin(), distance.begin()+start, 0) + 
                    accumulate(distance.begin() + destination, distance.end(), 0));
    }
};
// @lc code=end

