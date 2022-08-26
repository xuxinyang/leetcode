/*
 * @lc app=leetcode.cn id=458 lang=cpp
 *
 * [458] 可怜的小猪
 */

// @lc code=start
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (buckets == 1) return 0;
        vector<vector<int>> combinations(buckets + 1, vector<int>(buckets + 1));
        combinations[0][0] = 1;
        int iterations = minutesToTest / minutesToDie;
        vector<vector<int>> f(buckets, vector<int>(iterations + 1));
        for (int i = 0; i < buckets; i++) {
            f[i][0] = 1;
        }
        for (int j = 0; j < iterations; j++) {
            f[0][j] = 1;
        }
        for (int i = 1; i < buckets; i++)
        {
            combinations[i][0] = 1;
            combinations[i][i] = 1;
            for (int j = 1; j < i; j++) {
                combinations[i][j] = combinations[i-1][j-1] + combinations[i-1][j];
            }
            for (int j = 1; j <= iterations; j++) {
                for (int k = 0; k <= i; k++) {
                    f[i][j] += f[k][j-1] * combinations[i][i-k];
                }
            }
            if (f[i][iterations] >= buckets) {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end

