/*
 * @lc app=leetcode.cn id=565 lang=cpp
 *
 * [565] 数组嵌套
 */

// @lc code=start
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int cur=0;
            int j=i;
            while(nums[j]!=-1){
                cur++;
                int tmp=nums[j];
                nums[j]=-1;
                j=tmp;
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};
// @lc code=end

