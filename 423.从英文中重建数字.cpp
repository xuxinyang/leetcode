/*
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 */

// @lc code=start
class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> mp;
        string res;
        for (char c : s) {
            mp[c]++;
        }
        vector<int> nums(10);
        nums[0] = mp['z'], nums[2] = mp['w'];
        nums[4] = mp['u'], nums[6] = mp['x'];
        nums[8] = mp['g'];
        nums[3] = mp['h'] - nums[8];
        nums[5] = mp['f'] - nums[4];
        nums[7] = mp['s'] - nums[6];
        nums[1] = mp['o'] - nums[0] - nums[2] - nums[4];
        nums[9] = mp['i'] - nums[5] - nums[6] - nums[8];
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < nums[i]; j++)
            {
                res += char(i + '0');
            }
        }
        return res;
    }
};
// @lc code=end

