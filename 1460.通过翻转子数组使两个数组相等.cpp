/*
 * @lc app=leetcode.cn id=1460 lang=cpp
 *
 * [1460] 通过翻转子数组使两个数组相等
 */

// @lc code=start
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (target.size() != arr.size()) return false;
        map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] ++;
        }
        for (int i = 0; i < target.size(); i++) {
            mp[target[i]] --;
        }
        for (auto& item : mp) {
            if (item.second >= 1 || item.second < 0) return false;
        }
        return true;
    }
};
// @lc code=end

