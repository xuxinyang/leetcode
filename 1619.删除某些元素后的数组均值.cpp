/*
 * @lc app=leetcode.cn id=1619 lang=cpp
 *
 * [1619] 删除某些元素后的数组均值
 */

// @lc code=start
class Solution {
public:
    double trimMean(vector<int>& arr) {
        double sum = 0;
        for (int i = 0; i < arr.size(); i++) sum += arr[i];
        sort(arr.begin(), arr.end());
        int k = arr.size() * 0.05;
        for (int i = 0; i < k; i++) sum -= arr[i];
        for (int i = arr.size()-k; i < arr.size(); i++) sum -= arr[i];
        return sum/(arr.size()-2*k);
    }
 };
// @lc code=end

