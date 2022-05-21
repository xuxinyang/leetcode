/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 在长度 2N 的数组中找出重复 N 次的元素
 */

// @lc code=start
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;   // 存储数组中的元素
        for (int i = 0; i < nums.size(); ++i) {
            // 如果 nums[i] 已经在 s 中，则返回 nums[i]
            if (s.find(nums[i]) != s.end()) {
                return nums[i];
            }
            s.insert(nums[i]);
        }
        return -1;
    }
};
// @lc code=end

