/*
 * @lc app=leetcode.cn id=732 lang=cpp
 *
 * [732] 我的日程安排表 III
 */

// @lc code=start
class MyCalendarThree {
public:
    MyCalendarThree() {

    }
    
    int book(int start, int end) {
        int ans = 0;
        int maxBook = 0;
        cnt[start]++;
        cnt[end]--;
        for (auto &p : cnt) {
            ans += p.second;
            maxBook = max(maxBook, ans);
        }
        return maxBook;
    }
private:
    map<int, int> cnt;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// @lc code=end

