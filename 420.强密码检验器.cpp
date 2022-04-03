/*
 * @lc app=leetcode.cn id=420 lang=cpp
 *
 * [420] 强密码检验器
 */

// @lc code=start
class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        bool hasLower = false, hasUpper = false, hasDigit = false;
        for (char c: password)
        {
            if (islower(c)) hasLower = true;
            else if (isupper(c)) hasUpper = true;
            else hasDigit = true;
        }
        int categories = hasDigit + hasLower + hasUpper;
        if (n < 6) return max(6 - n, 3 - categories);
    }
};
// @lc code=end

