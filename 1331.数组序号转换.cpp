/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 *
 * [1331] 数组序号转换
 */

// @lc code=start
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());   // 排序
        unordered_map<int, int> ranks;  // 使用map去重并标记每个元素的排名
        vector<int> ans(arr.size());
        for (auto &a : sortedArr)
        {
            if (!ranks.count(a))
            {
                ranks[a] = ranks.size() + 1;    // 排序从1开始
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            ans[i] = ranks[arr[i]]; // 查找并返回元素的排名
        }
        return ans;
    }
};
// @lc code=end

