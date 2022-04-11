/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 */

// @lc code=start
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        if (n == 0) return true;
        int i = 0;
        while (i < n) {
            int cnt = 0;
            while (data[i] >> (7 - cnt) == 1) {
                cnt++;
            }
            if (cnt == 1 || cnt > 4) return false;
            i++;
            while (cnt--) {
                if (i >= n || data[i] >> 6 != 2) return false;
                i++;
            }
        }
        return true;
    }
};
// @lc code=end

