/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (canEat(piles, mid, h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
private:
    bool canEat(vector<int>& piles, int k, int h) {
        int sum = 0;
        for (int i = 0; i < piles.size(); i++) {
            sum += piles[i] / k;
            if (piles[i] % k != 0) {
                sum++;
            }
        }
        return sum <= h;
    }
};
// @lc code=end

