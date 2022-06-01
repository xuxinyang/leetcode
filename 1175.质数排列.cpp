/*
 * @lc app=leetcode.cn id=1175 lang=cpp
 *
 * [1175] 质数排列
 */

// @lc code=start
class Solution {
public:
    int numPrimeArrangements(int n) {
        long long res = 0;
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) {
                cnt++;
            }
        }
        res = factorial(cnt) * factorial(n - cnt) % 1000000007;
        return res;
    }
private:
    bool isPrime(int n) {
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0 || n == 1) {
            return false;
        }
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    long long factorial(int n) {
        if (n == 0) {
            return 1;
        }
        long long res = 1;
        for (int i = 1; i <= n; i++) {
            res *= i;
            res %= 1000000007;
        }
        return res % 1000000007;
    }
};
// @lc code=end

