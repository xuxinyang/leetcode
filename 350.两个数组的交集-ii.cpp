/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums1.size(); i++) {
            m[nums1[i]]++;
        }
        vector<int> res;
        for (int i = 0; i < nums2.size(); i++) {
            if (m[nums2[i]] > 0) {
                res.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }
        return res;
    }
};
// @lc code=end

