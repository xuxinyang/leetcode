/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n - 1; i++)
        {
            int l = i + 1, r = n - 1;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (numbers[i] + numbers[mid] == target)
                {
                    return {i + 1, mid + 1};
                }
                else if (numbers[i] + numbers[mid] < target)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return {};
    }
};
// @lc code=end

