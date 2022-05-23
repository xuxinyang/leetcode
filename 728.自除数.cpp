/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
private:
    bool isSelfDividing(int n) {
        int tmp = n;
        while (tmp) {
            int d = tmp % 10;
            if (d == 0 || n % d != 0) {
                return false;
            }
            tmp /= 10;
        }
        return true;
    }

};
// @lc code=end

