/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<long> sums(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return countRangeSum(sums, 0, n, lower, upper);
    }
private:
    int countRangeSum(vector<long>& sums, int l, int r, int lower, int upper) {
        if (l >= r) return 0;
        int mid = l + (r - l) / 2;
        int cnt = countRangeSum(sums, l, mid, lower, upper) + countRangeSum(sums, mid + 1, r, lower, upper);
        int i = mid, j = mid + 1, k = mid + 1;
        while (i >= l) {
            while (k <= r && sums[k] - sums[i] < lower) k++;
            cnt += k - j;
            while (k <= r && sums[k] - sums[i] <= upper) k++;
            i--;
            j = k;
        }
        return cnt;
    }
};
// @lc code=end

