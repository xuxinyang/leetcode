/*
 * @lc app=leetcode.cn id=982 lang=cpp
 *
 * [982] 按位与为零的三元组
 */

// @lc code=start

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int maxNum = 1<<16;
        int cnt[maxNum];
        memset(cnt, 0, sizeof(cnt));
        int n = nums.size();

        // 对于两个数字与结果计数
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ++cnt[nums[i] & nums[j]];
            }
        }

        // 遍历每个数字去找满足条件的数量
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            int full = maxNum - 1 - nums[i];
            // 遍历各种bit情况去计算: 移除最后一个数字
            // 这里得注意： 因为数字每次会改变，所以得基于原始值去与，否则会漏掉很多数字
            for (int j = full; j > 0; j = (j-1)&full)
            {
                res += cnt[j];
            }

            // 不要忘记加上0的情况，任何数字与0与都是0
            res += cnt[0];
        }
        return res;
    }
};
// @lc code=end

