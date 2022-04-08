/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mid * mid == num) {
                return true;
            } else if (mid * mid < num) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

