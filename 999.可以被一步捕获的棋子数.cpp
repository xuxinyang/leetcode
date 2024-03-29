/*
 * @lc app=leetcode.cn id=999 lang=cpp
 *
 * [999] 可以被一步捕获的棋子数
 */

// @lc code=start
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        int res = 0;
        for (int i = x - 1; i >= 0; i--) {
            if (board[i][y] == 'B') {
                break;
            } else if (board[i][y] == 'p') {
                res++;
                break;
            }
        }
        for (int i = x + 1; i < n; i++) {
            if (board[i][y] == 'B') {
                break;
            } else if (board[i][y] == 'p') {
                res++;
                break;
            }
        }
        for (int i = y - 1; i >= 0; i--) {
            if (board[x][i] == 'B') {
                break;
            } else if (board[x][i] == 'p') {
                res++;
                break;
            }
        }
        for (int i = y + 1; i < m; i++) {
            if (board[x][i] == 'B') {
                break;
            } else if (board[x][i] == 'p') {
                res++;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

