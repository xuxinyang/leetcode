/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 *
 * [1013] 将数组分成和相等的三个部分
 */

// @lc code=start
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int s = accumulate(A.begin(), A.end(), 0);
        if (s % 3 != 0) {
            return false;
        }
        int target = s / 3;
        int n = A.size(), i = 0, cur = 0;
        while (i < n) {
            cur += A[i];
            if (cur == target) {
                break;
            }
            ++i;
        }
        if (cur != target) {
            return false;
        }
        int j = i + 1;
        while (j + 1 < n) {  // 需要满足最后一个数组非空
            cur += A[j];
            if (cur == target * 2) {
                return true;
            }
            ++j;
        }
        return false;
    }
};
// @lc code=end

