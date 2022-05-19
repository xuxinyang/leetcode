/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) {
            return res;
        }
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && nums[j] == nums[j - 1] + 1) {
                ++j;
            }
            if (j - i == 1) {
                res.push_back(to_string(nums[i]));
            } else {
                res.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
            }
            i = j;
        }
        return res;
    }
};
// @lc code=end

