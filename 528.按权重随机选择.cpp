/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
class Solution {
public:
    Solution(vector<int>& w) {
        int sum = 0;
        for (int i = 0; i < w.size(); ++i) {
            sum += w[i];
            weight.push_back(sum);
        }
    }
    
    int pickIndex() {
        int r = rand() % weight.back();
        int l = 0, rr = weight.size() - 1;
        while (l < rr) {
            int mid = l + (rr - l) / 2;
            if (weight[mid] <= r) {
                l = mid + 1;
            } else {
                rr = mid;
            }
        }
        return l;
    }
private:
    vector<int> weight;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

