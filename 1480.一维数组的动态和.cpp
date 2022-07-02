/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        ans[0] = nums[0];
        for(int i=1;i<n;i++){
            ans[i] = ans[i-1] + nums[i];
        }
        return ans;
    }
};
// @lc code=end

