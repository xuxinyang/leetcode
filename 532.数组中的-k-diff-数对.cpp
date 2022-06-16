/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 */

// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (auto & num : nums) {
            cnt[num]++;
        }
        int res = 0;
        for (auto & p : cnt) {
            if (k == 0) {
                if (p.second > 1) {
                    res++;
                }
            } else {
                if (cnt.count(p.first + k)) {
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

