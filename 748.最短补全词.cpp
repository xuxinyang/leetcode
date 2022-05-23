/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短补全词
 */

// @lc code=start
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> m;
        for (char c : licensePlate) {
            if (c >= 'a' && c <= 'z') {
                m[c]++;
            } else if (c >= 'A' && c <= 'Z') {
                m[c + 32]++;
            }
        }
        string res;
        for (const auto& word : words) {
            unordered_map<char, int> tmp;
            for (char c : word) {
                tmp[c]++;
            }
            bool ok = true;
            for (auto& p : m) {
                if (tmp[p.first] < p.second) {
                    ok = false;
                    break;
                }
            }
            if (ok && (res.empty() || word.size() < res.size())) {
                res = word;
            }
        }
        return res;
    }
};
// @lc code=end

