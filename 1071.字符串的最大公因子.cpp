/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
 */

// @lc code=start
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        int len1 = str1.size();
        int len2 = str2.size();
        int len = len1 < len2 ? len1 : len2;
        int g = gcd(len1, len2);
        return str1.substr(0, g);
    }
};
// @lc code=end

