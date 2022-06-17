/*
 * @lc app=leetcode.cn id=481 lang=cpp
 *
 * [481] 神奇字符串
 */

// @lc code=start
class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        char last = '2';
        int ans = 1;
        for(int i = 2; i < n; i++){
            int curG = s[i] - '0';
            if(last == '1'){
                last = '2';
            }else{
                last = '1';
            }
            while(curG){
                s += last; 
                curG--;
            }
            
            if(s[i] == '1'){
                ++ans;
            }
        }

        return ans;
    }
};
// @lc code=end

