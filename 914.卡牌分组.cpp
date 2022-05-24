/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 */

// @lc code=start
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int n = deck.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[deck[i]]++;
        }
        int g = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == 1) {
                return false;
            }
            g = gcd(g, it->second);
        }
        return g >= 2;
    }
};
// @lc code=end

