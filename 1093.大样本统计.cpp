/*
 * @lc app=leetcode.cn id=1093 lang=cpp
 *
 * [1093] 大样本统计
 */

// @lc code=start
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minimum=INT_MAX,maximum=INT_MIN,mean,median,mode;
        long long sum=0,cnt=0,maxn=INT_MIN;
        for(int i=0;i<count.size();i++)
        {
            if(count[i]>0)
            {
                if(minimum==INT_MAX)minimum=i;
                maximum=i;
                sum+=(long long)count[i]*i;cnt+=count[i];
                if(count[i]>maxn)
                {
                    maxn=count[i];mode=i;
                }
            }
        }
        mean=(1.0*sum)/cnt;
        int x=0,l,r;
        for(int i=0;i<count.size();i++)
        {
            if(x<(cnt+1)/2&&x+count[i]>=(cnt+1)/2)l=i;//寻找中位数
            if(x<(cnt+2)/2&&x+count[i]>=(cnt+2)/2)r=i;
            x+=count[i];
        }
        median=(1.0*l+r)/2;
        return {minimum,maximum,mean,median,mode};
    }
};

// @lc code=end

