/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (__builtin_popcount(i) + __builtin_popcount(j) == turnedOn) {
                    res.push_back(to_string(i) + ":" + to_string(j));
                }
            }
        }
        return res;
    }
};
// @lc code=end

