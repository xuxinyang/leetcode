/*
 * @lc app=leetcode.cn id=854 lang=cpp
 *
 * [854] 相似度为 K 的字符串
 */

// @lc code=start
class Solution {
    int minCount = INT_MAX;
    int firstCount = 0;
    int n;
public:
    int kSimilarity(string s1, string s2) {
        n = s1.size();
        for (int i = 0; i < n; i++) if (s1[i] != s2[i])
        {
            for (int j = i + 1; j < n; ++j) {
                if (s1[i] == s2[j] && s1[j] == s2[i]) {
                    ++firstCount;
                    swap(s1[i], s1[j]);
                    break;
                }
            }
        }
        dfs(s1, s2, 0, 0);
        return minCount + firstCount;
    }
    void dfs(string &s1, string &s2, int currCount, int index) {
        if (currCount >= minCount) return;
        if (index == s1.size()) {
            minCount = min(minCount, currCount);
            return;
        }
        for (int i = index; i < n; ++i)
        {
            if (s1[i] == s2[i])
            {
                dfs(s1, s2, currCount, index+1);
            }
            for (int j = i+1; j < n; j++) {
                if (s1[i] == s2[j]) {
                    swap(s2[i], s2[j]);
                    dfs(s1, s2, currCount+1, index+1);
                    swap(s2[i], s2[j]);
                }
            }
            return;
        }
    }
};
// @lc code=end

