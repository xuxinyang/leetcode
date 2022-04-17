/*
 * @lc app=leetcode.cn id=1855 lang=cpp
 *
 * [1855] 下标对中的最大距离
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0, res = 0;
        for (j; j < n2; ++j)
        {
            while (i < n1 && nums1[i] > nums2[j])
            {
                ++i;
            }
            if (i < n1)
            {
                res = max(res, j - i);
            }
        }
        return res;
    }
};
// @lc code=end

