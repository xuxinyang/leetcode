/*
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 */

// @lc code=start
class Solution {
public:
    string fractionAddition(string expression) {
        long long denominator = 0, numerator = 1;
        int index = 0, n = expression.size();
        while (index < n)
        {
            long long denominator1 = 0, sign = 1;
            if (expression[index] == '-' || expression[index] == '+') {
                sign = expression[index] == '-' ? -1:1;
                index++;
            }
            while (index < n && isdigit(expression[index])) {
                denominator1 = denominator1 * 10 + expression[index] - '0';
                index++;
            }
            denominator1 = sign * denominator1;
            index++;
            long long numerator1 = 0;
            while (index < n && isdigit(expression[index])) {
                numerator1 = numerator1 * 10 + expression[index] - '0';
                index++;
            } 
            denominator = denominator * numerator1 + denominator1 * numerator;
            numerator *= numerator1; 
        }
        long long g = gcd(abs(denominator), numerator);
        return to_string(denominator/g) + "/" + to_string(numerator/g);
    }
};
// @lc code=end

