/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */

// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= n; i++) {
            res.push_back(i);
        }
        sort(res.begin(), res.end(), [](int a, int b) {
            return to_string(a) < to_string(b);
        });
        return res;  
    }
};
// @lc code=end

