/*
 * @lc app=leetcode.cn id=981 lang=cpp
 *
 * [981] 基于时间的键值存储
 */

// @lc code=start
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto &pairs = m[key];
        pair<int, string> p = {timestamp, string({127})};
        auto it = upper_bound(pairs.begin(), pairs.end(), p, [](const pair<int, string> &a, const pair<int, string> &b) {
            return a.first < b.first;
        });
        if (it == pairs.begin()) {
            return "";
        }
        return (--it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

