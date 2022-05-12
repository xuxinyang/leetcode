/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution {
private:
    vector<int> v;
public:
    Solution(vector<int>& nums) {
        v = nums;
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        int size = v.size();
        vector<int> ret(v.begin(), v.end());
        for (int i = size; i; i--) {
            swap(ret[random()%i], ret[i-1]);
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

