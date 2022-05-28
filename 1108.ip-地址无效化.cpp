/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

// @lc code=start
class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for (auto c : address) {
            if (c == '.') {
                res.push_back('[');
                res.push_back('.');
                res.push_back(']');
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};
// @lc code=end

