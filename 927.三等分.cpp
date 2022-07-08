/*
 * @lc app=leetcode.cn id=927 lang=cpp
 *
 * [927] 三等分
 */

// @lc code=start
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int cntOne=accumulate(arr.begin(),arr.end(),0);
        if(cntOne%3!=0)return {-1,-1};
        if(cntOne==0)return {0,(int)arr.size()-1};
        cntOne/=3;
        int beg1=0,beg2=0,beg3=0;
        int curOneCnt=0;
        for(int i=0;i<arr.size();i++){
            if(curOneCnt==0)beg1=i;
            if(curOneCnt==cntOne)beg2=i;
            if(curOneCnt==cntOne*2)beg3=i;
            if(arr[i]==1){
                curOneCnt++;
            }
        }
        int subLen=arr.size()-beg3;
        for(int i=0;i<subLen;i++){
            if(arr[beg1+i]!=arr[beg2+i]||arr[beg1+i]!=arr[beg3+i])return {-1,-1};
        }
        return {beg1+subLen-1,beg2+subLen};
    }
};
// @lc code=end

