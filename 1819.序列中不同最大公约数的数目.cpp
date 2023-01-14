/*
 * @lc app=leetcode.cn id=1819 lang=cpp
 *
 * [1819] 序列中不同最大公约数的数目
 */

// @lc code=start
class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> occured(maxVal + 1, false);
        for (int num:nums) {
            occured[num] = true;
        }
        int ans = 0;
        for (int i = 1; i <= maxVal; i++)
        {
            int subGcd = 0;
            for (int j = i; j <= maxVal; j += i)
            {
                if (occured[j])
                {
                    if (subGcd == 0) subGcd = j;
                    else
                    {
                        subGcd = __gcd(subGcd, j);
                    }
                    if (subGcd == i)
                    {
                        ans ++;
                        break;
                    }
                } 
                
            }
        }
        return ans;
    }
};
// @lc code=end

