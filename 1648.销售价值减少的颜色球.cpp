/*
 * @lc app=leetcode.cn id=1648 lang=cpp
 *
 * [1648] 销售价值减少的颜色球
 */

// @lc code=start
class Solution {
private:
    typedef long long ll;
    static constexpr int mod = 1e9+7;
    int n;
    int pre_in_l, pre_in_r;
public:
    ll check(const vector<int>& inventory, const vector<ll>& presums, ll orders, ll floor, int in_l, int in_r) {
        while (in_l+1 != in_r) {
            int mid = (in_l+in_r)>>1;
            if (inventory[mid] < floor) {
                in_l = mid;
            } else {
                in_r = mid;
            }
        }
        ll cnt = presums.back() - (presums[in_r]+(n-in_r)*floor);
        if (cnt > orders) {
            pre_in_l = in_l;
        } else {
            pre_in_r = in_r;
        }
        return cnt;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end());
        n = (int)inventory.size();
        vector<ll>presums(n+1);
        int maxVal = 0;
        for (int i=0; i<n; ++i) {
            presums[i+1] = presums[i]+inventory[i];
            maxVal = max(maxVal, inventory[i]);
        }
        int l = -1, r = maxVal+1;
        pre_in_l = -1;
        pre_in_r = n;
        while (l+1 < r) {
            int mid = (l+r)>>1;
            if (check(inventory, presums, orders, mid, pre_in_l, pre_in_r) > orders) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ll ans = 0;
        for (int x : inventory) {
            if (x > r) {
                ans += (ll)(x+r+1)*(x-r)/2;
                ans %= mod;
                orders -= x-r;
            }
        }
        ans += (ll)r * orders;
        ans %= mod;
        return (int)ans;
    }
};
// @lc code=end

