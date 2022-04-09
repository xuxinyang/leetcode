/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int l = 1;
        int r = num;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int t = num / mid;
            if (mid == t) {
                if (num % mid == 0) return true;
                l = mid + 1;
            } else if (t > mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

