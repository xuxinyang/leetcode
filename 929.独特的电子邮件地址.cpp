/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */

// @lc code=start
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (auto email : emails) {
            int i = 0;
            while (email[i] != '@') {
                if (email[i] == '+') {
                    ++i;
                    while (email[i] != '@') {
                        ++i;
                    }
                } else {
                    ++i;
                }
            }
            s.insert(email.substr(0, i));
        }
        return s.size();        
    }
};
// @lc code=end

