/*
 * @lc app=leetcode.cn id=632 lang=cpp
 *
 * [632] 最小区间
 */

// @lc code=start
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int rangeLeft = 0, rangeRight = INT_MAX;
        int size = nums.size();
        vector<int> next(size);

        auto cmp = [&](const int &u, const int& v) {
            return nums[u][next[u]] > nums[v][next[v]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int minValue = 0, maxValue = INT_MIN;
        for (int i = 0; i < size; ++i) {
            pq.emplace(i);
            maxValue = max(maxValue, nums[i][0]);
        }
        while (true) {
            int row = pq.top();
            pq.pop();
            minValue = nums[row][next[row]];
            if (maxValue - minValue < rangeRight - rangeLeft) {
                rangeRight = maxValue, rangeLeft = minValue;
            }
            if (next[row] == nums[row].size() - 1) {
                break;
            }
            ++next[row];
            maxValue = max(maxValue, nums[row][next[row]]);
            pq.emplace(row);
        }
        return {rangeRight, rangeLeft};

    }
};
// @lc code=end

