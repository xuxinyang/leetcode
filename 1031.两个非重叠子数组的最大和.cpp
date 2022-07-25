/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
 */

// @lc code=start
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<vector<int> > dp(nums.size(), vector<int>(4, 0));
        int presum = 0;
        int maxsum;
        for (int i = 0; i < firstLen; i++) presum += nums[i];
        maxsum = presum;
        dp[firstLen - 1][0]  = maxsum;
        for (int i = firstLen; i < nums.size(); i++)
        {
            presum -= nums[i-firstLen];
            presum += nums[i];
            maxsum = max(maxsum, presum);
            dp[i][0] = maxsum;
        }
        presum = 0;
        for (int i = 0; i < secondLen; i++) presum += nums[i];
        maxsum = presum;
        dp[secondLen - 1][1] = maxsum;
        for (int i = secondLen; i < nums.size(); ++i)
        {
            presum -= nums[i - secondLen];
            presum += nums[i];
            maxsum = max(maxsum, presum);
            dp[i][1] = maxsum;
        }
        presum = 0;
        for (int i = nums.size() - 1; i >= nums.size() - firstLen; --i)
        {
            presum += nums[i];
        }
        maxsum = presum;
        dp[nums.size() - firstLen][2] = maxsum;
        for (int i = nums.size() - firstLen - 1; i >= 0; --i)
        {
            presum -= nums[i + firstLen];
            presum += nums[i];
            maxsum = max(maxsum, presum);
            dp[i][2] = maxsum;
        }
        presum = 0;
        for (int i = nums.size() - 1; i >= nums.size() - secondLen; --i)
        {
            presum += nums[i];
        }
        maxsum = presum;
        dp[nums.size() - secondLen][3] = maxsum;
        for (int i = nums.size() - secondLen - 1; i >= 0; --i)
        {
            presum -= nums[i + secondLen];
            presum += nums[i];
            maxsum = max(maxsum, presum);
            dp[i][3] = maxsum;
        }
        int res = 0;
        for (int i = firstLen; i <= nums.size() - secondLen; ++i)
            res = max(res, dp[i - 1][0] + dp[i][3]);
        for (int i = secondLen; i <= nums.size() - firstLen; ++i)
            res = max(res, dp[i - 1][1] + dp[i][2]);
        return res;
    }
};
// @lc code=end

