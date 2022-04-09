/*
 * @lc app=leetcode.cn id=483 lang=cpp
 *
 * [483] 最小好进制
 */

// @lc code=start
class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);
        long long res = 1;
        long long left = 1;
        long long right = num;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long tmp = mid;
            long long sum = 1;
            while (tmp > 0) {
                sum = sum * tmp % num;
                tmp = tmp / 2;
            }
            if (sum == 0) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return to_string(res);
    }
};
// @lc code=end

