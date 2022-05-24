/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for (int i = 0; i < n; i++) {
            int m = image[i].size();
            for (int j = 0; j < m / 2; j++) {
                swap(image[i][j], image[i][m - j - 1]);
            }
            for (int j = 0; j < m; j++) {
                image[i][j] = !image[i][j];
            }
        }
        return image;
    }
};
// @lc code=end

