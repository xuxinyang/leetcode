/*
 * @lc app=leetcode.cn id=593 lang=cpp
 *
 * [593] 有效的正方形
 */

// @lc code=start
class Solution {
public:
    int getDistance(vector<int> p1, vector<int> p2)
    {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> v;
        v.push_back(p1), v.push_back(p2), v.push_back(p3), v.push_back(p4);
        sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        if (getDistance(v[0], v[1]) == 0 || getDistance(v[0], v[2]) == 0 || getDistance(v[0], v[3]) == 0)
            return false;
        if ((getDistance(v[0], v[1]) + getDistance(v[0], v[2]) == getDistance(v[1], v[2])) &&
            (getDistance(v[0], v[1]) + getDistance(v[1], v[3]) == getDistance(v[0], v[3])) &&
            (getDistance(v[0], v[2]) + getDistance(v[2], v[3]) == getDistance(v[0], v[3])) &&
            (getDistance(v[0], v[1]) == getDistance(v[0], v[2])))
            return true;
        return false;
    }
};
// @lc code=end

