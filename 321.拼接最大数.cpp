/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

// @lc code=start
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        for (int i = max(0, k - nums2.size()); i <= min(k, nums1.size()); ++i) {
            vector<int> nums3 = merge(maxArray(nums1, i), maxArray(nums2, k - i));
            if (greater(nums3, 0, res)) {
                res = nums3;
            }
        }
        return res;
    }
};
// @lc code=end

