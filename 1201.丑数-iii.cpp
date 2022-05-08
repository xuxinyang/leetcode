/*
 * @lc app=leetcode.cn id=1201 lang=cpp
 *
 * [1201] 丑数 III
 */

// @lc code=start
class Solution {
public:
    typedef long long ll;
    // greatest common divisor 最大公约数
    ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    // least common multiple 最小公倍数
    ll lcm(ll a, ll b) {
        return a * b / gcd(a, b);
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        ll ab = lcm(a, b), ac = lcm(a, c), bc = lcm(b, c);
        ll abc = lcm(ab, c);
        function<ll(ll)> uglyNumbersCount = [&](ll m) {
            return m / a + m / b + m / c - m / ab - m / ac - m / bc + m / abc;
        };
        ll countPerCycle = uglyNumbersCount(abc); // 一个最小公倍数周期内丑数个数
        int cycles = n/countPerCycle; // n 包含多少个最小公倍数周期
        // 搜索区间周期优化为 [abc*cycles, abc*(cycles+1)) 周期区间左闭右开
        ll l = abc*cycles-1, r = abc*(cycles+1);
        while (l+1 != r) {
            ll mid = (l+r)>>1;
            // 容斥原理：计算 cnt 为[1,mid]中的丑数个数
            ll cnt = uglyNumbersCount(mid);
            if (cnt < n) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return (int)r;
    }
};
// @lc code=end

