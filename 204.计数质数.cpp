/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                res++;
                for (int j = i + i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return res;
    }
};
// @lc code=end

