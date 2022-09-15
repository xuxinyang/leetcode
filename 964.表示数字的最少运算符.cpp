/*
 * @lc app=leetcode.cn id=964 lang=cpp
 *
 * [964] 表示数字的最少运算符
 */

// @lc code=start
class Solution {
private:
    unordered_map<int, int> target2num;
    int dfs(int x, int target) {
        if (target2num.find(target) != target2num.end()) {
            return target2num[target];
        }
        if (x == target) return 0;
        else if (x > target) return min(2*target-1, 2*(x-target));
        else
        {
            int p = 0;
            long xp = x;
            while (xp < target) {
                xp *= x;
                ++p;
            }
            if (xp - target >= target) {
                return p - 1 + 1 + dfs(x, target - xp/x);
            } 
            else {
                target2num[target] = min(p-1+dfs(x, target-xp/x), p+dfs(x, xp-target)) + 1;
                return target2num[target];
            }
        }
    }
public:
    int leastOpsExpressTarget(int x, int target) {
        return x != target ? dfs(x, target) : 0;
    }
};
// @lc code=end

