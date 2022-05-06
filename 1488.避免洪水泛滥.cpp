/*
 * @lc app=leetcode.cn id=1488 lang=cpp
 *
 * [1488] 避免洪水泛滥
 */

// @lc code=start
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), 1);
        unordered_map<int, int> m;
        set<int> s;

        for (int i = 0; i < rains.size(); i++) {
            int r = rains[i];
            if (r == 0) {
                s.insert(i);
                continue;
            } 
            if (m.count(r) != 0) {
                auto it = s.lower_bound(m[r]);
                if (it != s.end()) {
                    ans[*it] = r;
                    s.erase(it);
                } else {
                    return {};
                }
            }
            m[r] = i;
            ans[i] = -1;
        }
        return ans;
    }
};
// @lc code=end

