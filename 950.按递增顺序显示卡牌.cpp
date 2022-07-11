/*
 * @lc app=leetcode.cn id=950 lang=cpp
 *
 * [950] 按递增顺序显示卡牌
 */

// @lc code=start
class Solution {
public:
        vector<int> deckRevealedIncreasing(vector<int> &deck) {
        std::sort(deck.begin(), deck.end(), [](const int &lhs, const int &rhs) { return lhs > rhs; });
        std::deque<int> que;
        for (const auto &num: deck) {
            if (que.empty() || que.size() == 1) {
                que.push_front(num);
            } else {
                int x = que.back();
                que.pop_back();
                que.push_front(x);
                que.push_front(num);
            }
        }
        std::vector<int> res(que.begin(), que.end());
        return res;
    }
};
// @lc code=end

