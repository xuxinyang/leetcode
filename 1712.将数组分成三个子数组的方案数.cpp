/*
 * @lc app=leetcode.cn id=1712 lang=cpp
 *
 * [1712] 将数组分成三个子数组的方案数
 */

// @lc code=start
class Solution {
public:
    #define ll long long

    const static int mod = 1e9 + 7;

    int waysToSplit(vector<int>& nums) {
        int len = (int)nums.size();

        vector<int> pre(len + 1, 0);
        for(int i = 1; i <= len; i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }

        ll sum = 0;
        int l, r, s1, s2, s3;
        for(int i = 0, left, right, mid; i < len; i++) {
            left = i + 1, right = len - 1;
            while(left < right) {
                mid = (left + right) >> 1;

                s1 = pre[i + 1];
                s2 = pre[mid + 1] - s1;
                s3 = pre[len] - s1 - s2;

                if(s2 >= s1) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }

            l = left;
            left = i + 1, right = len - 1;
            while(left < right) {
                mid = (left + right) >> 1;

                s1 = pre[i + 1];
                s2 = pre[mid + 1] - s1;
                s3 = pre[len] - s1 - s2;
                
                if(s2 <= s3) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            r = left - 1;
            if(l <= r) {
                sum = (sum + r - l + 1) % mod;
            }
        }
        
        return sum;
    }
};
// @lc code=end

