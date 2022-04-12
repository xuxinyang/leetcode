/*
 * @lc app=leetcode.cn id=1539 lang=cpp
 *
 * [1539] 第 k 个缺失的正整数
 */

// @lc code=start
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr[0] > k) return k;
        int n = arr.size();
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (arr[mid] - mid - 1 < k) {
                i = mid + 1;
            } else {
                j = mid - 1;
                n = mid;
            }
        }
        return n + k;
    }
};
// @lc code=end

