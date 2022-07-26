/*
 * @lc app=leetcode.cn id=1041 lang=cpp
 *
 * [1041] 困于环中的机器人
 */

// @lc code=start
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dir = 0;
        for (char c : instructions)
        {
            if (c == 'G')
            {
                if (dir == 0) y++;
                else if (dir == 1) x++;
                else if (dir == 2) y--;
                else x--;
            }
            else if (c == 'L')
            {
                dir = (dir + 3) % 4;
            }
            else
            {
                dir = (dir + 1) % 4;
            }
        }
        return (x == 0 && y == 0) || dir != 0;
    }
};
// @lc code=end

