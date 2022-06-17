/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

// @lc code=start
class Solution {
public:
    void insert(vector<int> & arr, int k)
    {
        for (int i = arr.size() - 1; i > k; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[k] = 0;
    }
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        while (i < n-1) {
            if (arr[i] == 0) {
                insert(arr, i+1);
                i += 2;
            } else {
                i++;
            }
        }
    }

};
// @lc code=end

