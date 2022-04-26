/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int i = 0; i < nums.size(); ++i) {
            strs.push_back(to_string(nums[i]));
        }
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        string res = "";
        for (int i = 0; i < strs.size(); ++i) {
            res += strs[i];
        }
        if (res[0] == '0') {
            return "0";
        }
        return res;
    }
};
// @lc code=end

