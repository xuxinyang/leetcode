/*
 * @lc app=leetcode.cn id=1574 lang=cpp
 *
 * [1574] 删除最短的子数组使剩余数组有序
 */

// @lc code=start
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        const int n = (int)arr.size();
        int i = 1, j = n-1;
        while (i<n && arr[i-1]<=arr[i]) ++i;
        while (j-1>=0 && arr[j-1]<=arr[j]) --j;
        if (i > j) return 0; // arr已经有序
        int l = j, r = n-1; 
        int ans = j; // 最坏结果只保留right
        for (int k=0; k<i; ++k) {
            int target = arr[k];
            l = j-1; r = n; // 搜索right区间[j,n-1]
            while (l+1<r) {
                int mid = (l+r)>>1;
                if (arr[mid] < target) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            ans = min(ans, r-k-1);
        }
        return ans;
    }
};
// @lc code=end

