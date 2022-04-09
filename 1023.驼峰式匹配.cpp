/*
 * @lc app=leetcode.cn id=1023 lang=cpp
 *
 * [1023] 驼峰式匹配
 */

// @lc code=start
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (auto& query : queries) {
            res.push_back(match(query, pattern));
        }
        return res;
    }
    
};
// @lc code=end

