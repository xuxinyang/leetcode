/*
 * @lc app=leetcode.cn id=1146 lang=cpp
 *
 * [1146] 快照数组
 */

// @lc code=start
class SnapshotArray {
private:
    vector<map<int, int>> arr;
    int curr_idx = 0;
public:
    SnapshotArray(int length) {
        arr.resize(length);
    }
    
    void set(int index, int val) {
        arr[index][curr_idx] = val;
    }
    
    int snap() {
        return curr_idx++;
    }
    
    int get(int index, int snap_id) {
        auto it = arr[index].upper_bound(snap_id);
        if (it == arr[index].begin()) {
            return 0;
        }
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end

