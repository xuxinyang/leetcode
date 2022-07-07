/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
public:
    stack<pair<int, int>> monoS;
    StockSpanner() {

    }
    
    int next(int price) {
        pair<int, int> cur(price, 1);
        // 寻找左面连续位置的<= 当前元素
        while(!monoS.empty() && monoS.top().first <= price)
        {
            cur.second += monoS.top().second;
            monoS.pop();
        }
        monoS.push(cur);
        return cur.second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

