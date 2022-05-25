/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 */

// @lc code=start
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        vector<int> res;
        int carry = 0;
        for (int i = n - 1; i >= 0 || k > 0; i--) {
            int sum = (i >= 0 ? num[i] : 0) + k % 10 + carry;
            carry = sum / 10;
            res.push_back(sum % 10);
            k /= 10;
        }
        if (carry > 0) {
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

