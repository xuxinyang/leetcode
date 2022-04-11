/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            unordered_set<int> s;
            for (int num : nums) {
                s.insert(num & mask);
            }
            int tmp = res | (1 << i);
            for (int prefix : s) {
                if (s.count(tmp ^ prefix)) {
                    res = tmp;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

