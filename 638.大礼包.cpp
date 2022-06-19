/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 */

// @lc code=start
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        int res = dfs(price, special, needs, 0);
        return res;
    }
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int step) {
        int n = price.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (needs[i] > 0) {
                res += needs[i] * price[i];
            }
        }
        for (auto& x : special) {
            vector<int> tmp = needs;
            bool flag = true;
            for (int i = 0; i < n; i++) {
                if (tmp[i] < x[i]) {
                    flag = false;
                    break;
                }
                tmp[i] -= x[i];
            }
            if (flag) {
                res = min(res, x[n] + dfs(price, special, tmp, step + 1));
            }
        }
        return res;
    }
};
// @lc code=end

