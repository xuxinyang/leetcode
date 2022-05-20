/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> um;
        for (auto c : s) {
            um[c]++;
        }
        int ans = 0;
        for (auto i : um) {
            ans += i.second / 2 * 2;
        }
        if (ans < s.size()) {
            ans++;
        }
        return ans;
    }
};
// @lc code=end

