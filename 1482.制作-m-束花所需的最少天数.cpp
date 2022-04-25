/*
 * @lc app=leetcode.cn id=1482 lang=cpp
 *
 * [1482] 制作 m 束花所需的最少天数
 */

// @lc code=start
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < m * k) return -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check(bloomDay, mid, m, k))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
private:
    bool check(vector<int>& bloomDay, int day, int m, int k)
    {
        int bouquets = 0;
        int  flowers = 0;
        int len = bloomDay.size();
        for (int i = 0; i < len && bouquets < m; i++)
        {
            if (bloomDay[i] <= day)
            {
                flowers++;
                if (flowers == k)
                {
                    flowers = 0;
                    bouquets++;
                }
            }
            else
            {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }
};
// @lc code=end

