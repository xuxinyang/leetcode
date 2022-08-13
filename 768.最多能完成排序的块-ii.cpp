/*
 * @lc app=leetcode.cn id=768 lang=cpp
 *
 * [768] 最多能完成排序的块 II
 */

// @lc code=start
class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        unordered_map<int, int> m;
        int res = 0;
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            int x = arr[i], y = sortedArr[i];
            m[x]++;
            if (m[x] == 0)
                m.erase(x);
            m[y]--;
            if (m[y] == 0)
                m.erase(y);
            if (m.empty())
                res++;
        }
        return res;
    }
};
// @lc code=end
