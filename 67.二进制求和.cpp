/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        if (n == 0) return b;
        if (m == 0) return a;
        int i = n - 1, j = m - 1;
        string res = "";
        int carry = 0;
        while (i >= 0 || j >= 0)
        {
            int ai = i >= 0 ? a[i] - '0' : 0;
            int bi = j >= 0 ? b[j] - '0' : 0;
            int sum = ai + bi + carry;
            carry = sum / 2;
            sum %= 2;
            res = to_string(sum) + res;
            --i;
            --j;
        }
        if (carry)
        {
            res = "1" + res;
        }
        return res;
    }
};
// @lc code=end

