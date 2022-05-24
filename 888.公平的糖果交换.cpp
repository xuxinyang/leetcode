/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 */

// @lc code=start
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aliceSum = 0, bobSum = 0;
        for (int i : aliceSizes) {
            aliceSum += i;
        }
        for (int i : bobSizes) {
            bobSum += i;
        }
        int diff = (aliceSum - bobSum) / 2;
        unordered_set<int> aliceSet;
        for (int i : aliceSizes) {
            aliceSet.insert(i);
        }
        for (int i : bobSizes) {
            if (aliceSet.count(i + diff)) {
                return {i + diff, i};
            }
        }
        return {};
    }
};
// @lc code=end

