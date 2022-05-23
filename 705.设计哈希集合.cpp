/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

// @lc code=start
class MyHashSet {
private:
    unordered_set<int> s;
    unordered_map<int, int> mp;
public:
    MyHashSet() {

    }
    
    void add(int key) {
        if (mp.count(key)) {
            mp[key] = 1;
        }
    }
    
    void remove(int key) {
        if (mp.count(key)) {
            mp.erase(key);
        }
    }
    
    bool contains(int key) {
        return mp.count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

