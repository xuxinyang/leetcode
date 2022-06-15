/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution {
public:
    int n;  // 数组的长度
    int k;  // 子集的数量
    vector<int> nums_sorted;
    vector<int> buckets;
    int average;

    // cur 当前应该分配的数的下标
    bool dfs(vector<int>& buckets, int cur) {
        if (cur == n) {
            // 剪枝补充：走到这里的每个桶一定是平均的，所以可以不用判断
            // 直接返回 true，但是这里剪枝收益很小很小
            for (int i = 0; i < k; i++) {
                if (buckets[i] != average) return false;
            }
            return true;
        }

        // 回溯
        int res = false;
        for (int i = 0; i < k; i++) {
            // 剪枝1：第一个数只需分配至一个 k 位置即可，可减少 (k-1)/k 个递归树
            if (cur == 0 && i != 0) break;

            // 剪枝2：如果一个子集的和 大于 应该的平均值，显然不可能
            if (buckets[i] + nums_sorted[cur] > average) continue;

            // 剪枝3：如果当前桶和上一个桶内的元素和相等，则跳过
            // 原因：如果元素和相等，那么 nums[index] 选择上一个桶和选择当前桶可以得到的结果是一致的
            // 这是最nb的剪枝,1764 ms -> 0 ms
            if (i > 0 && buckets[i] == buckets[i - 1]) continue;

            buckets[i] += nums_sorted[cur];
            res = dfs(buckets, cur + 1);
            buckets[i] -= nums_sorted[cur];
            if (res) break;
        }
        return res;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        nums_sorted = nums;
        n = nums.size();
        this->k = k;
        buckets.resize(k, 0);

        // 先排序，尽早触发 dfs 中的剪枝，不符合条件的递归尽快结束
        sort(nums_sorted.begin(), nums_sorted.end(), greater<int>());

        int total = 0;
        for (int num : nums) total += num;
        if (total % k) return false;  // nums 不能平分成 k 份，直接返回
        average = total / k;

        return dfs(buckets, 0);
    }
};
// @lc code=end

