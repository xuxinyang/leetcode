/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) {
                sum += num1[i--] - '0';
            }
            if (j >= 0) {
                sum += num2[j--] - '0';
            }
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry) {
            res.push_back(carry + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

