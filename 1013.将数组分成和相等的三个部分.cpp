/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 *
 * [1013] 将数组分成和相等的三个部分
 */

// @lc code=start
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        if (sum % 3 != 0) {
            return false;
        }
        int target = sum / 3;
        int cur = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            cur += arr[i];
            if (cur == target) {
                count++;
                cur = 0;
            }
        }
        return count == 3;
    }
};
// @lc code=end

