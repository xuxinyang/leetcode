/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n, 0);
        for (int i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }
        string res;
        k--;
        for (int i = 0; i < n; ++i) {
            int idx = k / factorial(n - i - 1);
            res += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
            k %= factorial(n - i - 1);
        }
        return res;
    }
    int factorial(int n) {
        if (n <= 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }
};
// @lc code=end

