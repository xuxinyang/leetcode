/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
private:
    stack<int> s;
    vector<int> v;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            v.push_back(val);
        }else{
            if(val < v.back()){
                v.push_back(val);
            }else{
                v.push_back(v.back());
            }
        }
        s.push(val);
    }
    
    void pop() {
        s.pop();
        v.pop_back();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return v.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

