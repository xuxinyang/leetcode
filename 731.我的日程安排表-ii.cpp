/*
 * @lc app=leetcode.cn id=731 lang=cpp
 *
 * [731] 我的日程安排表 II
 */

// @lc code=start
class MyCalendarTwo {
private:
    map<int, int> differential_array_book; // 差分数组
public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        // 假设成功插入日程安排
        // 利用差分数组特性，下面操作相当于将日期[start,end)的日程安排数量+1
        differential_array_book[start]++;
        differential_array_book[end]--;

        int book_num = 0;
        for(auto it = differential_array_book.begin(); it != differential_array_book.end();it++) {
            book_num += it->second; // 利用差分数组特性计算某日期的日程安排数量
            if(book_num >= 3) {
                // 如果出现三重预定，回滚日程插入
                differential_array_book[start]--;
                differential_array_book[end]++;
                // 这个操作只是为了节省时间，对正确性没有影响
                // 差分数组为0是默认情况，可以删除
                if(differential_array_book[start] == 0)
                    differential_array_book.erase(start);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

