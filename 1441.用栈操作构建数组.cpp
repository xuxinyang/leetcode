/*
 * @lc app=leetcode.cn id=1441 lang=cpp
 *
 * [1441] 用栈操作构建数组
 */

// @lc code=start
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int prev = 0;
        for (int number: target) {
            for (int i = 0; i < number - prev - 1; i++) {
                res.emplace_back("Push");
                res.emplace_back("Pop");
            }
            res.emplace_back("Push");
            prev = number;
        }
        return res;
    }
};
// @lc code=end

