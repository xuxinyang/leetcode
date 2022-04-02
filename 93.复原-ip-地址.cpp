/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() < 7 || s.size() > 15) {
            return res;
        }
        dfs(s, 0, 0, res);
        return res;
    }
    
};
// @lc code=end

