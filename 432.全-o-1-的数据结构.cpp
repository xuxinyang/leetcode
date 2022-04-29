/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */

// @lc code=start
class AllOne {
    list<pair<unordered_set<string>, int>> buckets;
    unordered_map<string, list<pair<unordered_set<string>, int>>::iterator> bucket_map;
public:
    AllOne() {

    }
    
    void inc(string key) {
        if (bucket_map.count(key)) {
            auto it = bucket_map[key], nxt = next(it);
            if (nxt == buckets.end() || nxt->second > it->second + 1) {
                unordered_set<string> s({key});
                bucket_map[key] = buckets.emplace(nxt, s, it->second + 1);
            } else {
                nxt->first.emplace(key);
                bucket_map[key] = nxt;
            }
            it->first.erase(key);
            if (it->first.empty()) {
                buckets.erase(it);
            }
        } else {
            if (buckets.empty() || buckets.back().second > 1) {
                unordered_set<string> s({key});
                buckets.emplace_back(s, 1);
            } else {
                buckets.begin()->first.emplace(key);
            }
            bucket_map[key] = buckets.begin();
        }
    }
    
    void dec(string key) {
        auto it = bucket_map[key];
        if (it->second == 1) {
            bucket_map.erase(key);
        } else {
            auto pre = prev(it);
            if (it == buckets.begin() || pre->second < it->second - 1) {
                unordered_set<string> s({key});
                bucket_map[key] = buckets.emplace(it, s, it->second - 1);
            } else {
                pre->first.emplace(key);
                bucket_map[key] = pre;
            }
        }
        it->first.erase(key);
        if (it->first.empty()) {
            buckets.erase(it);
        }
    }
    
    string getMaxKey() {
        if (buckets.empty()) {
            return "";
        }
        return *buckets.begin()->first.begin();
    }
    
    string getMinKey() {
        if (buckets.empty()) {
            return "";
        }
        return *buckets.rbegin()->first.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

