/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        // set -> vector
        vector<int> v(s.begin(), s.end());
        if (v.size() < 3) {
            return *max_element(v.begin(), v.end());
        }
        sort(v.begin(), v.end());
        return v[v.size() - 3];
    }
};
// @lc code=end

