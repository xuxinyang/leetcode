/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 */

// @lc code=start
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for (int i = 0; i < houses.size(); ++i) {
            int pos = lower_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
            int left = pos == 0 ? INT_MAX : heaters[pos - 1] - houses[i];
            int right = pos == heaters.size() ? INT_MAX : houses[i] - heaters[pos];
            res = max(res, min(left, right));
        }
        return res;
    }
};
// @lc code=end

