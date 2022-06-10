/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto& num : nums) {
            m[num]++;
        }

        vector<int> res;
        priority_queue<pair<int, int>> que;
        for (auto& p : m) {
            que.emplace(p.second, p.first);
        }

        while (k--) {
            res.emplace_back(que.top().second);
            que.pop();
        }
        return res;
    }
};
// @lc code=end

