/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> m;
        for (int i = 0; i < arr2.size(); ++i) {
            m[arr2[i]] = i;
        }
        vector<int> res;
        for (int i = 0; i < arr1.size(); ++i) {
            res.push_back(arr1[i]);
        }
        sort(res.begin(), res.end(), [&m](int a, int b) {
            if (m.find(a) != m.end() && m.find(b) != m.end()) {
                return m[a] < m[b];
            } else if (m.find(a) != m.end()) {
                return true;
            } else if (m.find(b) != m.end()) {
                return false;
            } else {
                return a < b;
            }
        });
        return res;
    }
};
// @lc code=end

