/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int quickSelect(vector<int> &a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else if (q < index) {
            return quickSelect(a, q + 1, r, index);
        } else {
            return quickSelect(a, l, q - 1, index);
        }
    }
    inline int randomPartition(vector<int> &a, int l, int r) {
        int i = l + rand() % (r - l + 1);
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int> &a, int l, int r) {
        int x = a[r];
        int i = l - 1;
        for (int j = l; j < r; j++) {
            if (a[j] <= x) {
                i++;
                swap(a[i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
// @lc code=end

