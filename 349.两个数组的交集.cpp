/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 初始化数组
        vector<int> res;
        unordered_map<int, int> nums1_map;
        for (int i = 0; i < nums1.size(); ++i) {
            nums1_map[nums1[i]] = i;
        }
        
        // 开始求解
        for (int i = 0; i < nums2.size(); ++i) {
            if (nums1_map.find(nums2[i]) != nums1_map.end()) {
                res.push_back(nums2[i]);
            }
        }
        
        return res;
    }
};
// @lc code=end

