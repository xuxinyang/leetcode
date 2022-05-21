/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '-') {
                continue;
            }
            ans.push_back(s[i]);
            if (ans.size() == k) {
                ans.push_back('-');
            }
        }
        if (ans.size() > 0 && ans[ans.size() - 1] == '-') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

