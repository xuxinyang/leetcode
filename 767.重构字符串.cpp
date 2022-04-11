/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */

// @lc code=start
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        if (n <= 1) return s;
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        vector<pair<char, int>> v;
        for (auto p : m) {
            v.push_back(p);
        }
        sort(v.begin(), v.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
        if (v[0].second > (n + 1) / 2) return "";
        string res = "";
        int i = 0;
        while (i < n) {
            res += v[0].first;
            v[0].second--;
            if (v[0].second == 0) {
                v.erase(v.begin());
            }
            if (i < n - 1) {
                res += v[0].first;
                v[0].second--;
                if (v[0].second == 0) {
                    v.erase(v.begin());
                }
            }
            i += 2;
        }
        return res;
    }
};
// @lc code=end

