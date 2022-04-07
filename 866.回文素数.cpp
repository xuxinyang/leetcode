/*
 * @lc app=leetcode.cn id=866 lang=cpp
 *
 * [866] 回文素数
 */

// @lc code=start
class Solution {
public:
    int primePalindrome(int n) {
        // 欧拉筛法
        vector<bool> isPrime(1e8, true);
        for (int i = 2; i <= 1e8; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 1e8; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        if (n <= 1) return 2;
        for (int i = n; ; ++i) {
            if (isPrime[i] && isPalindrome(i)) return i;
        }
    }
private:
    bool isPalindrome(int n) {
        string s = to_string(n);
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};
// @lc code=end

