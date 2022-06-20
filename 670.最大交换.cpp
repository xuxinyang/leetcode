/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

// @lc code=start
class Solution {
public:
    static char cmp(char a , char b){  //辅助将string从大到小排序
        return a>b;
    }
    int maximumSwap(int num) {
        string change = to_string(num);
        string exchange = change;
        sort(exchange.begin(),exchange.end(),cmp);
    
        char small = ' ';    
        char big = ' ';
        for(int i = 0 ; i< change.size(); i++){
            if(exchange[i] != change [i]) { 
                small = change[i];
                big = exchange[i];
                change[i]= exchange[i];
                break;
            }
        }
        for(int i = change.size()-1 ; i >=0; i--){
          if(small!= ' ' && change[i] == big) {
                change[i] =small;
                break;
            }
        }

        int res = stoi(change);
        return res;
    }
};
// @lc code=end

