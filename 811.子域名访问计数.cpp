/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

// @lc code=start
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for (auto& cpdomain : cpdomains) {
            int pos = cpdomain.find(' ');
            int count = stoi(cpdomain.substr(0, pos));
            string domain = cpdomain.substr(pos + 1);
            for (int i = 0; i < domain.size(); i++) {
                if (domain[i] == '.') {
                    m[domain.substr(i + 1)] += count;
                }
            }
            m[domain] += count;
        }
        vector<string> res;
        for (auto& p : m) {
            res.push_back(to_string(p.second) + " " + p.first);
        }
        return res;
    }
};
// @lc code=end

