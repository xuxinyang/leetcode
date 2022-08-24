/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] 使序列递增的最小交换次数
 */

// @lc code=start
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n1 = 0, s1 = 1;
        for (int i = 1; i < nums1.size(); i++) {
            int n2 = INT_MAX, s2 = INT_MAX;
            if (nums1[i-1] < nums1[i] && nums2[i-1] < nums2[i]) {
                n2 = min(n2, n1);
                s2 = min(s2, s1+1);
            }
            if (nums1[i-1] < nums2[i] && nums2[i-1] < nums1[i]) {
                n2 = min(n2, s1);
                s2 = min(s2, n1 + 1);
            }
            n1 = n2;
            s1 = s2;
        }
        return min(n1, s1);
    }
};
// @lc code=end

