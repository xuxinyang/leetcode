/*
 * @lc app=leetcode.cn id=2299 lang=cpp
 *
 * [2299] 强密码检验器 II
 */

// @lc code=start
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.length() < 8) return false;
        bool flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
        string comparestr = "!@#$%^&*()-+";
        for (int i = 0; i < password.length(); i++)
        {
            if (i > 0 && password[i] == password[i-1]) return false;
            if (password[i] >= 'a' && password[i] <= 'z') flag1 = 1;
            if (password[i] >= 'A' && password[i] <= 'Z') flag2 = 1;
            if (password[i] >= '0' && password[i] <= '9') flag3 = 1;
            for (int j = 0; j < comparestr.length(); j++)
            {
                if (password[i] == comparestr[j])
                {
                    flag4 = 1;
                    break;
                }
            }
        }
        if (!flag1 || !flag2 || !flag3 || !flag4) return false;
        return true;
    }
};
// @lc code=end

