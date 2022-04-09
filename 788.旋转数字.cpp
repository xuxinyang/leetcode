/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */

// @lc code=start
class Solution {
public:
    int rotatedDigits(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (isValid(i)) {
                res++;
            }
        }
        return res;
    }
private:
    bool isValid(int n) {
        int cnt = 0;
        while (n) {
            int d = n % 10;
            if (d == 3 || d == 4 || d == 7) {
                return false;
            }
            if (d == 2 || d == 5 || d == 6 || d == 9) {
                cnt++;
            }
            n /= 10;
        }
        return cnt > 0;
    }
};
// @lc code=end

