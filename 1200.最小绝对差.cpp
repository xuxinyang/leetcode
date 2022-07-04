/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 *
 * [1200] 最小绝对差
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> res;
        int minDiff = INT_MAX;
        for (int i = 0; i < n-1; i++) {
            if (arr[i+1] - arr[i] < minDiff) {
                minDiff = arr[i+1] - arr[i];
                res = {{arr[i], arr[i+1]}};
            }
            else if (arr[i+1] - arr[i] == minDiff) {
                res.emplace_back(initializer_list<int>{arr[i], arr[i+1]});
            }
        }
        return res;
    }
};
// @lc code=end

