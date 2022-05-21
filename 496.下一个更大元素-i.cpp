/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); ++i) {
            int j = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            if (j == nums2.size() - 1 || nums2[j + 1] <= nums1[i]) {
                ans.push_back(-1);
            } else {
                ans.push_back(nums2[j + 1]);
            }
        }
        return ans;
    }
};
// @lc code=end

