/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int> > res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(make_pair(nums[i], i));
        }
        sort(res.begin(), res.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });
        for (int i = 0; i < n; i++)
        {
            int l = i + 1, r = n - 1;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (res[mid].first + res[i].first == target)
                {
                    return vector<int>{res[i].second, res[mid].second};
                }
                else if (res[mid].first + res[i].first < target)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return vector<int>{-1, -1};
    }
};
// @lc code=end

