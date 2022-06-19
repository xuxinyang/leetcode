/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 */

// @lc code=start
class MyCalendar {
    map<int, int> d;
public:
    MyCalendar() : d{{INT_MIN, INT_MIN}, {INT_MAX,INT_MAX}} { }

    bool book(int start, int end) {
        auto it = d.lower_bound(start);
        if(it->first < end) return false;
        if((--it)->second > start) return false;
        d[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

