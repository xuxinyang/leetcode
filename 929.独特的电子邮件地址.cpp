/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */

// @lc code=start
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> res;
        for (auto &email : emails) {
            string local;
            for (char c: email)
            {
                if (c == '+' || c == '@') {
                    break;
                }
                if (c != '.') {
                    local += c;
                }
            }
            res.insert(local + email.substr(email.find('@')));
        }
        return res.size();
    }
};
// @lc code=end

