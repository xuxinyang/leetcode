/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */

// @lc code=start
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        for (int i = 0; i < order.size(); i++) {
            m[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            if (!compare(words[i], words[i + 1], m)) {
                return false;
            }
        }
        return true;
    }
    bool compare(string& a, string& b, unordered_map<char, int>& m) {
        int n = min(a.size(), b.size());
        for (int i = 0; i < n; i++) {
            if (m[a[i]] > m[b[i]]) {
                return false;
            } else if (m[a[i]] < m[b[i]]) {
                return true;
            }
        }
        return a.size() <= b.size();
    }
};
// @lc code=end

