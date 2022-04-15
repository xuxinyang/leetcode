/*
 * @lc app=leetcode.cn id=1346 lang=cpp
 *
 * [1346] 检查整数及其两倍数是否存在
 */

// @lc code=start
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (int i = 0; i < arr.size(); i++) {
            if (s.find(arr[i] * 2) != s.end()) {
                return true;
            }
            if (arr[i] % 2 == 0 && s.find(arr[i] / 2) != s.end()) {
                return true;
            }
            s.insert(arr[i]);
        }
        return false;
    }
};
// @lc code=end

