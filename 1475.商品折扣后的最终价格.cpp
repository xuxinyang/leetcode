/*
 * @lc app=leetcode.cn id=1475 lang=cpp
 *
 * [1475] 商品折扣后的最终价格
 */

// @lc code=start
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res;
        for (int i = 0; i < prices.size(); i++)
        {
            bool flag = 1;
            for (int j = i + 1; j < prices.size(); j++)
            {
                // cout << prices[i] << "\n";
                if (prices[j] <= prices[i])
                {
                    flag = 0;
                    res.push_back(prices[i] - prices[j]); 
                    break;
                }
            }
            if (flag) res.push_back(prices[i]);
        }
        return res;
    }
};
// @lc code=end

