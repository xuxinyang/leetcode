/*
 * @lc app=leetcode.cn id=864 lang=cpp
 *
 * [864] 获取所有钥匙的最短路径
 */

// @lc code=start
class Solution {
public:
    //建立自定义的搜索结构，x,y代表坐标，step 步数，status 钥匙的状态（使用二进制存储）
    struct node{
        int x, y, step, status;
    };
    //cnt 钥匙的数量   sx,sy起点坐标 mark标记去重
    int n, m, sx, sy, cnt = 0, mark[30][30][64] = {0};
    int b2[7] = {1, 2, 4, 8 ,16, 32, 64};
    //方向数组
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int shortestPathAllKeys(vector<string>& grid) {
        n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                //找到起点，在把他复原成.
                if(grid[i][j] == '@'){
                    sx = i, sy = j;
                    grid[i][j] = '.';
                }
                //统计钥匙数量
                if(grid[i][j] >= 'a' && grid[i][j] <= 'f'){
                    cnt++;
                }
            }
        }
        queue<node> que;
        //起点入队
        que.push((node){sx,sy, 0, 0});
        //标记起点
        mark[sx][sy][0] = 1;
        while(!que.empty()){
            node temp = que.front();
            que.pop();
            //往四个方向走
            for(int i = 0; i < 4; i++){
                int x = temp.x + dir[i][0];
                int y = temp.y + dir[i][1];
                //判断越界
                if(x < 0 || y < 0 || x == n || y == m || mark[x][y][temp.status] == 1){
                    continue;
                }
                //遇到. 状态不变，步数+1
                if(grid[x][y] == '.'){
                    mark[x][y][temp.status] = 1;
                    que.push((node){x,y,temp.step + 1, temp.status});                    
                }
                // 遇到钥匙
                else if(grid[x][y] >= 'a' && grid[x][y] <= 'f'){
                    //先判断是不是终点
                    if((temp.status | b2[grid[x][y] - 'a']) == b2[cnt] - 1){
                        return temp.step + 1;
                    }
                    //标记去重，
                    mark[x][y][temp.status] = 1;
                    //按位或运算，保证不会重复减
                    mark[x][y][temp.status | b2[grid[x][y] - 'a']] = 1;
                    que.push((node){x, y, temp.step + 1, temp.status | b2[grid[x][y] - 'a']});
                }
                //遇到锁，必须保证有钥匙
                else if(grid[x][y] >= 'A' && grid[x][y] <= 'F' && (temp.status & b2[grid[x][y] - 'A']) != 0){
                    mark[x][y][temp.status] = 1;
                    que.push((node){x, y, temp.step + 1, temp.status});
                }
            }
        }
        return -1;
    }
};
// @lc code=end

