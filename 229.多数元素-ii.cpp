/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 多数元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0, ca = 0, cb = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == a) {
                ca++;
            } else if (nums[i] == b) {
                cb++;
            } else if (ca == 0) {
                a = nums[i];
                ca = 1;
            } else if (cb == 0) {
                b = nums[i];
                cb = 1;
            } else {
                ca--;
                cb--;
            }
        }
        ca = cb = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == a) {
                ca++;
            } else if (nums[i] == b) {
                cb++;
            }
        }
        vector<int> ret;
        if (ca > n / 3) {
            ret.push_back(a);
        }
        if (cb > n / 3) {
            ret.push_back(b);
        }
        return ret;
    }
};
// @lc code=end

