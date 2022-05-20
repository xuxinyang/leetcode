/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i <= n / 2; ++i) {
            if (n % i == 0) {
                bool flag = true;
                for (int j = 0; j < i; ++j) {
                    for (int k = j + i; k < n; k += i) {
                        if (s[j] != s[k]) {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

