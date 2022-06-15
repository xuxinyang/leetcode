/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (auto c : s) {
            ++cnt[c - 'a'];
        }
        vector<bool> visited(26, false);
        string ans;
        for (auto c : s) {
            --cnt[c - 'a'];
            if (visited[c - 'a']) {
                continue;
            }
            while (!ans.empty() && ans.back() > c && cnt[ans.back() - 'a'] > 0) {
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans += c;
            visited[c - 'a'] = true;
        }
        return ans;
    }
};
// @lc code=end

