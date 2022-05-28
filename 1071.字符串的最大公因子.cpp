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
        int len = str1.size();
        int i = 0;
        while (i < len && str1[i] == str2[i]) {
            i++;
        }
        return str1.substr(0, i);
    }
};
// @lc code=end

