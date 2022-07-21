/*
 * @lc app=leetcode.cn id=1016 lang=cpp
 *
 * [1016] 子串能表示从 1 到 N 数字的二进制串
 */

// @lc code=start
class Solution {
public:
    string to_str(int n) {
        string ans;
        while (n) {
            ans += (n % 2 + '0');
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool queryString(string s, int n) {
        for (int i = 1; i <= n; i++) {
            if (s.find(to_str(i)) == string::npos) return false;
        }
        return true;   
    }
};
// @lc code=end

