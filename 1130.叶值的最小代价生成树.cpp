/*
 * @lc app=leetcode.cn id=1130 lang=cpp
 *
 * [1130] 叶值的最小代价生成树
 */

// @lc code=start
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0, pos = 0;
        while (arr.size() > 1) {
            int Min = INT_MAX;
            for (int i = 0; i < arr.size() - 1; ++i) {
                if (Min > arr[i] * arr[i + 1])
                {
                    Min = arr[i] * arr[i + 1];
                    pos = arr[i] < arr[i + 1] ? i : i + 1;
                }
            }
            ans += Min;
            arr.erase(arr.begin() + pos);
        }
        return ans;
    }
};
// @lc code=end

