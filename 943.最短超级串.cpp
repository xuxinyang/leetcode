/*
 * @lc app=leetcode.cn id=943 lang=cpp
 *
 * [943] 最短超级串
 */

// @lc code=start
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();

        // 预先计算overrlap
        int overlap[n][n];
        memset(overlap, 0, sizeof(overlap));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i != j)
                {
                    int maxN = min(words[i].size(), words[j].size());
                    for (int k = maxN; k >= 0; --k)
                    {
                        string currWord = words[j].substr(0, k);
                        if (equal(currWord.rbegin(), currWord.rend(), words[i].rbegin()))
                        {
                            // 去最大重叠的长度
                            overlap[i][j] = k;
                            // cout << i << " " << j << " " << k << endl;
                            break;
                        }
                    }
                }
            }
        }

        // 初始化 动态规划 和 父状态 数组
        int maxD = 1 << n;
        int d[maxD][n];
        memset(d, 0, sizeof(d));
        int parent[maxD][n];
        memset(parent, 0, sizeof(parent));
        for (int mask = 0; mask < maxD; ++mask)
        {
            // 初始化为无效值 -1
            for (int i = 0; i < n; ++i)
            {
                parent[mask][i] = -1;
            }
            // 考虑各种从 i 到 j 的可能性
            for (int j = 0; j < n; ++j)
            {
                if (((mask >> j) & 1) <= 0)
                {
                    continue;
                }
                // 上一个mask
                int lastMask = mask ^ (1<<j);
                // 忽略空的状态
                if (lastMask == 0)
                {
                    continue;
                }

                for (int i = 0; i < n; ++i)
                {
                    if (((lastMask >> i) & 1) > 0)
                    {
                        int curr = d[lastMask][i] + overlap[i][j];
                        if (curr > d[mask][j])
                        {
                            d[mask][j] = curr;
                            parent[mask][j] = i;
                        }
                    }
                }
            }
        }
        // 找出重合最大d[maxD-1][i]的数值的序号 p 
        int p = 0;
        for (int i = 1; i < n; ++i)
        {
            if (d[maxD-1][i] > d[maxD-1][p])
            {
                p = i;
            }
        }

        // 倒序去构建结果
        int seq[n];
        // 记录哪些被记录了，其他就是直接附加即可
        bool seen[n];
        memset(seen, 0, sizeof(seen));
        int i = n-1;
        // 最后一个满状态是 maxN -1
        int currMask = maxD - 1;
        while (p != -1)
        {
            seq[i] = p;
            --i;
            seen[p] = true;
            int p2 = parent[currMask][p];
            currMask ^= 1 << p;
            p = p2;
        }
        // 增加没有seen的单词
        for (int j = 0; j < n; ++j)
        {
            if (!seen[j])
            {
                seq[i] = j;
                --i;
            }
        }

        // 构建字符串
        string res = words[seq[0]];
        for (int i = 1; i < n; ++i)
        {
            res += words[seq[i]].substr(overlap[seq[i-1]][seq[i]]);
        }

        return res;
    }
};
// @lc code=end

