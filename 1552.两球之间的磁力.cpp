/*
 * @lc app=leetcode.cn id=1552 lang=cpp
 *
 * [1552] 两球之间的磁力
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1, r = position.back() - position[0];
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(position, mid, m)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
private:
    bool check(vector<int>& position, int x, int m) {
        int k = position[0];
        int cnt = 1;
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - k >= x) {
                k = position[i];
                cnt++;
            }
        }
        return cnt >= m;
    }
};
// @lc code=end

