/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (m == 1) return *max_element(nums.begin(), nums.end());
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (check(nums, mid, m))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
private:
    bool check(vector<int>& nums, int target, int m) {
        int n = nums.size();
        int cnt = 1;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (sum + nums[i] > target) {
                sum = nums[i];
                cnt++;
                if (cnt > m) return false;
            }
            else {
                sum += nums[i];
            }
        }
        return true;
    }

};
// @lc code=end

