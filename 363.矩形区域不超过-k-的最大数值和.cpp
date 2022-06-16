/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */

// @lc code=start
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = INT_MIN;
        for (int left = 0; left < n; left++) {
            vector<int> sum(m, 0);
            for (int right = left; right < n; right++) {
                for (int i = 0; i < m; i++) {
                    sum[i] += matrix[i][right];
                }
                int cur = helper(sum, k);
                res = max(res, cur);
            }
        }
        return res;
    }
    int helper(vector<int>& sum, int k) {
        int n = sum.size();
        int res = INT_MIN;
        int cur = 0;
        set<int> s;
        s.insert(0);
        for (int i = 0; i < n; i++) {
            cur += sum[i];
            auto it = s.lower_bound(cur - k);
            if (it != s.end()) {
                res = max(res, cur - *it);
            }
            s.insert(cur);
        }
        return res;
    }
};
// @lc code=end

