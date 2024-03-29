/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
class Solution {
public:
    //题解1：动态规划，时间复杂度O(n^2)，空间复杂度O(n)
    int findLongestChain_1(vector<vector<int>>& pairs) {
        if(pairs.empty())return 0;
        sort(pairs.begin(),pairs.end(),[](const vector<int>& a,const vector<int>& b){
            return (a[0]==b[0]&&a[1]<b[1])||(a[0]<b[0]);
        });
        int n=pairs.size(),res=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }

    //解法2：动态规划+二分法，时间复杂度O(nlogn)，空间复杂度O(n)
    int findLongestChain_2(vector<vector<int>>& pairs){
        if(pairs.empty())return 0;
        sort(pairs.begin(),pairs.end(),[](const auto& a,const auto& b){
            return (a[0]<b[0])||(a[0]==b[0]&&a[1]<b[1]);
        });
        vector<vector<int>> dp;
        for(auto& p:pairs){
            //二分法寻找大于等于p[0]的最小值dp[i][1]
            int left=0,right=dp.size();
            while(left<right){//进入while循环区间内至少有2个元素，退出循环的极值只有0或size
                int mid=left+((right-left)>>1);
                if(dp[mid][1]>=p[0])right=mid;
                else left=mid+1;
            }
            //dp[size-1][1]<p[0]，则更新最长数对链的长度
            if(left>=dp.size())dp.emplace_back(p);
            //dp[left][1]大于（等于）p[0]同时也大于p[1]，那么我们更新dp[left]为p，这样可以将left变小，以便形成最长的数对链
            else if(dp[left][1]>p[1])dp[left]=p;
        }
        return dp.size();
    }

    //解法3：区间贪心法，转换为435. 计算无重叠子区间数
    int findLongestChain(vector<vector<int>>& pairs){
        if(pairs.empty())return 0;
        //区间排序：按右端点进行排序，若右端点不相等，按右端点由小到大进行排序；若右端点相等，则按左端点由小到大进行排序
        sort(pairs.begin(),pairs.end(),[](const auto& a,const auto& b){
            return (a[1]<b[1])||(a[1]==b[1]&&a[0]<b[0]);
        });
        //count初始化为1，用来统计不重复子区间个数的
        int count=1,end=pairs[0][1];
        for(const auto& p:pairs){
            if(p[0]>end){//区间不相交，需要更新边界以及不重复区间个数，注意不能有等号，即区间端点不能连续
                count++;
                end=p[1];
            }
        }
        return count;
    }
};
// @lc code=end

