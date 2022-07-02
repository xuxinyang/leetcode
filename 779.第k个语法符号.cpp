/*
 * @lc app=leetcode.cn id=779 lang=cpp
 *
 * [779] 第K个语法符号
 */

// @lc code=start
class Solution {
public: 
    int kthGrammar(int N, int K) {
        if(N==1 && K==1)return 0;
        int up = K/2 + K%2;
        int num = kthGrammar(N-1,up);
        if((num+K)%2==0)return 1;
        return 0;
    }
};
// @lc code=end

