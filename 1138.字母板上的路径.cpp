/*
 * @lc app=leetcode.cn id=1138 lang=cpp
 *
 * [1138] 字母板上的路径
 */

// @lc code=start
class Solution {
public:
    string alphabetBoardPath(string target) {
        int x = 0, y = 0;
        string s = "";
        for (char ch: target)
        {
            int a = (ch - 97) / 5, b = (ch - 97) % 5;
            while (a - x && !(a == 5 && x == 4))
            {
                if (a - x > 0) x++, s+='D';
                else x--, s += 'U';
            }
            while (b - y)
            {
                if (b - y > 0) y++, s += 'R';
                else y--, s += 'L';
            }
            if (a - x == 1)
            {
                x++;
                s+='D';
            }
            s += '!';
        }
        return s;
    }
};
// @lc code=end

