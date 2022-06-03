/*
 * @lc app=leetcode.cn id=949 lang=cpp
 *
 * [949] 给定数字能组成的最大时间
 */

// @lc code=start
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        string res = "";
        do {
            string s = to_string(arr[0]) + to_string(arr[1]) + ":" + to_string(arr[2]) + to_string(arr[3]);
            if (s > res) {
                res = s;
            }
        } while (next_permutation(arr.begin(), arr.end()));
        return res;
    }
};
// @lc code=end

