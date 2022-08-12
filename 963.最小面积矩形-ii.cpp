/*
 * @lc app=leetcode.cn id=963 lang=cpp
 *
 * [963] 最小面积矩形 II
 */

// @lc code=start
class Solution
{
public:
    double minAreaFreeRect(vector<vector<int>> &points)
    {
        int n = points.size();

        set<pair<int, int>> points_set; // 加速查找 hash，空间换取时间
        for (auto v : points)
            points_set.insert(make_pair(v[0], v[1]));
        double res = DBL_MAX;
        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0], y1 = points[i][1]; //第一个点，是个顶点
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int x2 = points[j][0], y2 = points[j][1]; //第二个点
                for (int k = j + 1; k < n; k++)           //第三个点
                {
                    if (k == i)
                        continue;
                    int x3 = points[k][0], y3 = points[k][1];
                    int x4 = x2 + x3 - x1, y4 = y2 + y3 - y1;
                    if (points_set.count(pair<int, int>{x4, y4}) != 0) // p4存在
                    {
                        vector<int> v21{x2 - x1, y2 - y1};
                        vector<int> v31{x3 - x1, y3 - y1};
                        if (v21[0] * v31[0] + v21[1] * v31[1] == 0)
                        {
                            double cur_area = pow(pow(v21[0], 2) + pow(v21[1], 2), 0.5) * pow(pow(v31[0], 2) + pow(v31[1], 2), 0.5);
                            if (cur_area < res)
                                res = cur_area;
                        }
                    }
                }
            }
        }

        return (res != DBL_MAX ? res : 0);
    }
};
// @lc code=end
