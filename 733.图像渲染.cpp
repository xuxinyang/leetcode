/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        dfs(image, visited, sr, sc, oldColor, newColor);
        return image;
    }
private:
    void dfs(vector<vector<int>>& image, vector<vector<bool>>& visited, int i, int j, int oldColor, int newColor) {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || visited[i][j] || image[i][j] != oldColor) return;
        visited[i][j] = true;
        image[i][j] = newColor;
        dfs(image, visited, i - 1, j, oldColor, newColor);
        dfs(image, visited, i + 1, j, oldColor, newColor);
        dfs(image, visited, i, j - 1, oldColor, newColor);
        dfs(image, visited, i, j + 1, oldColor, newColor);
    }
};
// @lc code=end

