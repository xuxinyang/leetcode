/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        vector<pair<int, int>> v;
        for (int i = 0; i < score.size(); ++i) {
            v.push_back({score[i], i});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        for (int i = 0; i < v.size(); ++i) {
            if (i == 0) {
                ans.push_back("Gold Medal");
            } else if (i == 1) {
                ans.push_back("Silver Medal");
            } else if (i == 2) {
                ans.push_back("Bronze Medal");
            } else {
                ans.push_back(to_string(i + 1));
            }
        }
        return ans;
    }
};
// @lc code=end

