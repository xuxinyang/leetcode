/*
 * @lc app=leetcode.cn id=2080 lang=cpp
 *
 * [2080] 区间内查询数字的频率
 */

// @lc code=start
class RangeFreqQuery {
private:
    unordered_map<int, vector<int> > m;
public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            m[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        const vector<int> &v = m[value];
        auto l = lower_bound(v.begin(), v.end(), left);
        auto r = upper_bound(v.begin(), v.end(), right);
        return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// @lc code=end

