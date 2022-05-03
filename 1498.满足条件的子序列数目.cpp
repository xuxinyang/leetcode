/*
 * @lc app=leetcode.cn id=1498 lang=cpp
 *
 * [1498] 满足条件的子序列数目
 */

// @lc code=start
class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    static constexpr int MAXN = 1e5 + 5;
    int f[MAXN];
    void init() {
        f[0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            f[i] = (long long)(f[i - 1] * 2) % MOD;
        }
    }
    int numSubseq(vector<int>& nums, int target) {
        init();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size() && nums[i] * 2 <= target; ++i) {
            int maxValue = target - nums[i];
            int pos = upper_bound(nums.begin(), nums.end(), maxValue) - nums.begin() -1;
            int contribution = (pos >= i) ? f[pos - i] : 0;
            ans = (ans + contribution) % MOD;
        }
        return ans;
    }
};
// @lc code=end

