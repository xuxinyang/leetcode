/*
 * @lc app=leetcode.cn id=517 lang=cpp
 *
 * [517] 超级洗衣机
 */

// @lc code=start
class Solution {
public:
    int findMinMoves(vector<int> &machines) {
        int tot = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (tot % n) {
            return -1;
        }
        int avg = tot / n;
        int ans = 0, sum = 0;
        for (int num: machines) {
            num -= avg;
            sum += num;
            ans = max(ans, max(abs(sum), num));
        }
        return ans;
    }
};
// @lc code=end

