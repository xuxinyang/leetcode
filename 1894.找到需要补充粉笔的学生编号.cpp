/*
 * @lc app=leetcode.cn id=1894 lang=cpp
 *
 * [1894] 找到需要补充粉笔的学生编号
 */

// @lc code=start
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long> pre(n + 5, 0);
        long sum = 0;
        for (int i = 0; i < n; i++) {
            pre[i+1] = pre[i] + chalk[i];
            sum += chalk[i];
        }
        k = k % sum;
        int ans = upper_bound(pre.begin()+1, pre.end()-4, k) - pre.begin();
        return ans-1;
    }
};
// @lc code=end

