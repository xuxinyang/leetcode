/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 */

// @lc code=start
class Solution {
public:
    string solveEquation(string equation) {
        // 转换成ax = b;
        int a = 0, b = 0, tmp = 0;
        bool left = true, x_negative = false, pre_zero = false;
        // left记录是在方程左边还是右边，x_negative记录x和常数对应的符号
        // pre_zero记录x是否有前导0
        for (auto &i: equation) {
            // 遇到 '-', '+', '=', 把前面的tmp加到b上
            if (i == '-' || i == '+') {
                if (!x_negative) tmp = -tmp;
                b += tmp;
                tmp = 0;
                x_negative = i == '-' ? left : !left;
            }
            else if (i == '=') {
                if (x_negative) tmp = -tmp;
                b -= tmp;
                left = false;
                tmp = 0;
                x_negative = !left;
                pre_zero = false;
            } 
            else if (i >= '0' && i <= '9') {
                tmp = tmp * 10 + (i - '0');
                if (tmp == 0) pre_zero = true;
                else pre_zero = false;
            } 
            // 遇到x，把tmp加到x的系数a上
            else if (i == 'x') {
                if (x_negative) tmp *= -1;
                if (tmp == 0) {
                    if (!pre_zero) {
                        if (x_negative) --a;
                        else ++a;  
                    }
                }
                else a += tmp;
                tmp = 0;
            }
            //cout << a << ' ' << b << endl;
        }
        // 最后是常数的话，加到b上
        if (tmp != 0) {
            if (!x_negative) tmp *= -1;
            b += tmp;
        }

        if (a == 0 && b != 0) return "No solution";
        if (a == 0) return "Infinite solutions";
        return "x=" + to_string(b / a);
    }
};
// @lc code=end

