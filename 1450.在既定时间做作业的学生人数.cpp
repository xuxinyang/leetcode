/*
 * @lc app=leetcode.cn id=1450 lang=cpp
 *
 * [1450] 在既定时间做作业的学生人数
 */

// @lc code=start
class Solution
{
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        vector<int> diff(1005, 0);
        for (int i = 0; i < startTime.size(); i++)
        {
            diff[startTime[i]]++;
            diff[endTime[i] + 1]--;
        }
        for (int i = 1; i <= 1000; i++)
        {
            diff[i] += diff[i - 1];
        }
        return diff[queryTime];
    }
};
// @lc code=end
