/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
class Solution {
public:
    int superEggDrop(int k, int n) {
        if ((-1+sqrt(1+8*n*k))/2 == (int)(-1+sqrt(1+8*n*k))/2) {
            return (-1+sqrt(1+8*n*k))/2;
        }
        else
        {
            return superEggDrop(k, n-1)+1;
        }
    }
};
// @lc code=end

