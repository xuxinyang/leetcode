/*
 * @lc app=leetcode.cn id=991 lang=cpp
 *
 * [991] 坏了的计算器
 */

// @lc code=start
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (startValue < target) {
            ans++;
            if (target % 2 == 0) {
                target /= 2;
            } else {
                target = target + 1;
            }
        }
        return ans - target + startValue;
    }
};
// @lc code=end

