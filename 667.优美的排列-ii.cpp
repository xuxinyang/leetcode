/*
 * @lc app=leetcode.cn id=667 lang=cpp
 *
 * [667] 优美的排列 II
 */

// @lc code=start
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int>ans(n);
        int num1=1,num2=k+1,i=0;
        while(num1<=num2){
            if(num1==num2){
                ans[i++]=num1;
                break;
            }
            ans[i++]=num1;
            ans[i++]=num2;
            num1++;
            num2--;
        }
        while(i<n){
            ans[i++]=i+1;
        }
        return ans;
    }
};
// @lc code=end

