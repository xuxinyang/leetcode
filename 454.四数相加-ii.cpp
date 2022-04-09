/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // 初始化数组
        unordered_map<int, int> nums1_map;
        for (int i = 0; i < nums1.size(); ++i) {
            nums1_map[nums1[i]]++;
        }
        
        unordered_map<int, int> nums2_map;
        for (int i = 0; i < nums2.size(); ++i) {
            nums2_map[nums2[i]]++;
        }
        
        unordered_map<int, int> nums3_map;
        for (int i = 0; i < nums3.size(); ++i) {
            nums3_map[nums3[i]]++;
        }
        
        unordered_map<int, int> nums4_map;
        for (int i = 0; i < nums4.size(); ++i) {
            nums4_map[nums4[i]]++;
        }
        
        // 开始求解
        int res = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                for (int k = 0; k < nums3.size(); ++k) {
                    for (int l = 0; l < nums4.size(); ++l) {
                        if (nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0) {
                            res += nums1_map[nums1[i]] * nums2_map[nums2[j]] * nums3_map[nums3[k]] * nums4_map[nums4[l]];
                        }
                    }
                }
            }
        }
        
        return res;
    }
};
// @lc code=end

