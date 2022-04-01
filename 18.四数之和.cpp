/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            vector<vector<int>> tmp = threeSum(nums, i + 1, target - nums[i]);
            for (auto &v : tmp)
            {
                v.push_back(nums[i]);
                res.push_back(v);
            }
            while (i < n - 1 && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums, int start, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = start; i < n; ++i) 
        {
            vector<vector<int>> tmp = twoSum(nums, i + 1, target - nums[i]);
            for (auto& v : tmp) 
            {
                v.push_back(nums[i]);
                res.push_back(v);
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) 
            {
                ++i;
            }
        }
        return res;
    }
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        int low = start, high = nums.size() - 1;
        vector<vector<int>> res;
        while (low < high) 
        {
            int sum = nums[low] + nums[high];
            int left = nums[low], right = nums[high];
            if (sum < target) while (low < high && nums[low] == left) low++;
            else if (sum > target) while (low < high && nums[high] == right) high--;
            else 
            {
                res.push_back({left, right});
                while (low < high && nums[low] == left) low++;
                while (low < high && nums[high] == right) high--;
            }
        }
        return res;
    }
};
// @lc code=end

