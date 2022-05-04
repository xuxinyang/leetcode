/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
class Solution {
public:
    int result= 1;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return -1;
        if(grid.size()==1) return 1;
        int n=grid[0].size();
        int d[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        queue<pair<int,int>> vec;
        vec.push({0,0});
        while(!vec.empty()){
            int len=vec.size();
            for(int i=0;i<len;i++){
                auto a = vec.front();    
                vec.pop();           
                int x = a.first;
                int y = a.second;
                for(int j = 0;j<8;j++){
                    int xx = x+d[j][0]; //依次遍历八个方向（横坐标）
                    int yy = y+d[j][1]; //依次遍历八个方向（纵坐标）
                    if(xx>=0 && xx<n && yy>=0 && yy<n && grid[xx][yy]==0) {
                        if(xx==n-1 && yy==n-1)
                            return result+1; 
                        vec.push({xx,yy});
                        grid[xx][yy]=1;
                    }
                }
            }
            result+=1;
        }
        return -1;
    }
};
// @lc code=end

