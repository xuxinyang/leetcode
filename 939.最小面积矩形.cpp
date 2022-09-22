/*
 * @lc app=leetcode.cn id=939 lang=cpp
 *
 * [939] 最小面积矩形
 */

// @lc code=start
#define xy(x,y) (1<<15)*x+y
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int>mp;
        for(int i=0;i<points.size();i++){
            int x=points[i][0],y=points[i][1];
            mp.insert(xy(x,y));
        }
        int ans=INT_MAX;
        for(int i=0;i<points.size();i++){
            int x0=points[i][0],y0=points[i][1];
            for(int j=i+1;j<points.size();j++){
                int x1=points[j][0],y1=points[j][1];
                if(x0==x1||y0==y1)continue;
                if(mp.count(xy(x0,y1))&&mp.count(xy(x1,y0))){
                    ans=min(ans,abs(x0-x1)*abs(y0-y1));
                }
            }
        }
        return ans==INT_MAX?0:ans;
    }
};
// @lc code=end

