/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteUnique(nums, 0, ans);
        return ans;
    }
private:
    void permuteUnique(vector<int>& nums, int start, vector<vector<int>>& ans) {
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }
        set<int> s;
        for (int i = start; i < nums.size(); i++) {
            if (s.count(nums[i]) == 0) {
                swap(nums[i], nums[start]);
                permuteUnique(nums, start + 1, ans);
                swap(nums[i], nums[start]);
                s.insert(nums[i]);
            }
        }
    }
};
// @lc code=end

