/*
 * @lc app=leetcode.cn id=777 lang=cpp
 *
 * [777] 在LR字符串中交换相邻字符
 */

// @lc code=start
class Solution {
public:
    bool canTransform(string start, string end) {
        int sz = start.size();
        int i = 0, j = 0;
        while(i < sz && j < sz){
            while(i < sz && start[i] == 'X') i ++;
            while(j < sz && end[j] == 'X') j ++;
            if(i < sz && j < sz){
                if(start[i] != end[j] || (start[i] == 'L' && i < j)
                || (start[i] == 'R' && i > j))
                    return false;
                else{
                    i ++; j ++;
                }
            }
        }
        while(i < sz && start[i] == 'X') i ++;
        while(j < sz && end[j] == 'X') j ++;
        if(i != j) return false;
        return true;
    }
};
// @lc code=end

