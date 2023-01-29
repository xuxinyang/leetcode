/*
 * @lc app=leetcode.cn id=2315 lang=cpp
 *
 * [2315] 统计星号
 */

// @lc code=start
class Solution {
public:
    int countAsterisks(string s) {
        int cnt = 0;
        int flag = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '|')
                if (flag == -1 || flag == 1)
                    flag = 0;
                else flag = 1; 
            if ((flag == -1 || flag == 1) && s[i] == '*')
            {
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

