/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // 初始化数组
        unordered_map<int, int> nums1_map;
        for (int i = 0; i < nums1.size(); ++i) {
            nums1_map[nums1[i]] = i;
        }
        
        // 开始求解
        int res = 0;
        for (int i = 0; i < nums2.size(); ++i) {
            if (nums1_map.find(nums2[i]) != nums1_map.end()) {
                res = max(res, i - nums1_map[nums2[i]] + 1);
            }
        }
        
        return res;
    }
};
// @lc code=end

