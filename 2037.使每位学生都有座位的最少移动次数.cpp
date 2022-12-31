/*
 * @lc app=leetcode.cn id=2037 lang=cpp
 *
 * [2037] 使每位学生都有座位的最少移动次数
 */

// @lc code=start
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int ans = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        for (int i = 0; i < seats.size(); i++)
        {
            ans += abs(students[i]-seats[i]);
        }
        return ans;
    }
};
// @lc code=end

