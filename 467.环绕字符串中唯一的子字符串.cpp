/*
 * @lc app=leetcode.cn id=467 lang=cpp
 *
 * [467] 环绕字符串中唯一的子字符串
 */

// @lc code=start
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        vector<int> count(26);
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && (p[i] - p[i - 1] == 1 || p[i] - p[i - 1] == -25)) {
                maxLen++;
            } else {
                maxLen = 1;
            }
            count[p[i] - 'a'] = max(count[p[i] - 'a'], maxLen);
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res += count[i];
        }
        return res;
    }
};
// @lc code=end

