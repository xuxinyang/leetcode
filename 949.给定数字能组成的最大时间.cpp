/*
 * @lc app=leetcode.cn id=949 lang=cpp
 *
 * [949] 给定数字能组成的最大时间
 */

// @lc code=start
class Solution
{
public:
    string largestTimeFromDigits(vector<int> &A)
    {
        int res = -1;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (j != i)
                    for (int k = 0; k < 4; k++)
                        if (k != i && k != j)
                        {
                            int l = 6 - i - j - k; //确定l的位置  6=0+1+2+3
                            int hours = 10 * A[i] + A[j];
                            int mins = 10 * A[k] + A[l];
                            if (hours < 24 && mins < 60)
                                res = max(res, hours * 60 + mins);
                        }
        if (res >= 0)
        {
            string str;
            if (res / 60 < 10)
                str += '0';
            str += to_string(res / 60);
            str += ':';
            if (res % 60 < 10)
                str += '0';
            str += to_string(res % 60);
            return str;
        }
        return "";
    }
};

// @lc code=end
