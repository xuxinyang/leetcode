/*
 * @lc app=leetcode.cn id=1053 lang=cpp
 *
 * [1053] 交换一次的先前排列
 */

// @lc code=start
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        if (arr.size() <= 1) {
            return arr;
        }
        int left = 0, right = 0;
        for (int i = arr.size() - 1; i > 0; i--) {
            if (arr[i - 1] > arr[i]) {
                left = i - 1;
                break;
            }
        }
        int max_val = arr[left + 1];
        if (max_val < arr[left]) {
            right = left + 1;
        }
        for (int i = left + 1; i <= arr.size() - 1; i++) {
            if (arr[i] < arr[left] && max_val < arr[i]) {
                right = i;
            }
        }
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        return arr;
    }
};
// @lc code=end

