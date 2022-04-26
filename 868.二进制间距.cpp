/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

// @lc code=start
class Solution {
    int i = 0;
public:
    int binaryGap(int n) {
        int ans = 0;
        int pre = -1;
        while (n) {
            if (n & 1) {
                if (pre != -1) {
                    ans = max(ans, i - pre);
                }
                pre = i;
            }
            n >>= 1;
            i++;
        }
        return ans;
    }
};
// @lc code=end

