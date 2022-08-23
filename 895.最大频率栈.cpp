/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] 最大频率栈
 */

// @lc code=start
class FreqStack {
public:
    struct node {
        int key, val, index;
        bool operator < (const node& a) const{
            if (val != a.val) {
                return val > a.val;
            }
            return index > a.index;
        }
    };
    multiset<node> S;
    unordered_map<int, int> mp;
    int index;
    FreqStack() {
        index = 0;
    }
    
    void push(int val) {
        mp[val]++;
        S.insert({val, mp[val], index});
        index++;
    }
    
    int pop() {
        int key = S.begin() -> key;
        S.erase(S.begin());
        mp[key]--;
        return key;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

