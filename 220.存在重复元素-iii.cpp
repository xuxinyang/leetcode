/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2 || k < 1 || t < 0) return false;
        multiset<long> s;
        for (int i = 0; i < nums.size(); i++) {
            auto it = s.lower_bound(nums[i] - t);
            if (it != s.end() && *it - nums[i] <= t) return true;
            if (it != s.begin() && *prev(it) - nums[i] <= t) return true;
            s.insert(nums[i]);
            if (i >= k) s.erase(s.find(nums[i - k]));
        }
        return false;
    }
};
// @lc code=end

