/*
 * @lc app=leetcode.cn id=947 lang=cpp
 *
 * [947] 移除最多的同行或同列石头
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, int> parent;
    int count = 0;
    int find(int x)
    {
        if (parent.find(x) == parent.end())
        {
            parent[x] = x;
            count++;
        }
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void uniod(int x, int y)
    {
        int parent1 = find(x);
        int parent2 = find(y);
        if (parent1 == parent2)
            return;
        parent[parent1] = parent2;
        count--;
    }
    int removeStones(vector<vector<int>> &stones)
    {
        for (auto &stone : stones)
        {
            uniod(stone[0] + 10001, stone[1]);
        }
        return stones.size() - count;
    }
};
// @lc code=end
