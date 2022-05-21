/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        string ans;
        bool neg = num < 0;
        if (neg) {
            num = -num;
        }
        while (num > 0) {
            ans.push_back(num % 7 + '0');
            num /= 7;
        }
        if (neg) {
            ans.push_back('-');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

