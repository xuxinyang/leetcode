/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            bool flag = true;   
            for (int j = 1; j < strs.size(); ++j) { 
                if (strs[j][i] < strs[j - 1][i]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

