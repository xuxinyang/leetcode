/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest {
vector<int> nums;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > nums[k - 1]) {
                nums[k - 1] = nums[i];
                k--;
            }
        }
        for (int i = k; i < nums.size(); ++i) {
            nums[i] = nums[nums.size() - 1];
        }
        nums.resize(k);
    }
    
    int add(int val) {
        if (nums.size() == 0) {
            nums.push_back(val);
            return val;
        }
        if (val > nums[0]) {
            nums.insert(nums.begin(), val);
            return nums[0];
        }
        if (val < nums[nums.size() - 1]) {
            nums.push_back(val);
            return nums[nums.size() - 1];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (val < nums[i]) {
                nums.insert(nums.begin() + i, val);
                return nums[i];
            }
        }
        return nums[nums.size() - 1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

