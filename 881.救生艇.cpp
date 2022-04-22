/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

// @lc code=start
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int l = 0, r = n - 1;
        int res = 0;
        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                l++;
                r--;
                res++;
            }
            else {
                res++;
                r--;
            }
        }
        return res;
    }
};
// @lc code=end

