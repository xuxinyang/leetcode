/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        for (int i = 0; i < list1.size(); ++i) {
            m[list1[i]] = i;
        }
        vector<string> res;
        int min_sum = INT_MAX;
        for (int i = 0; i < list2.size(); ++i) {
            if (m.find(list2[i]) != m.end()) {
                int sum = i + m[list2[i]];
                if (sum < min_sum) {
                    min_sum = sum;
                    res.clear();
                    res.push_back(list2[i]);
                } else if (sum == min_sum) {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};
// @lc code=end

