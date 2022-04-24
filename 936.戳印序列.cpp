/*
 * @lc app=leetcode.cn id=936 lang=cpp
 *
 * [936] 戳印序列
 */

// @lc code=start
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size();
        int inDegree[n-m+1];
        for (int i = 0; i < n-m+1; i++) {
            inDegree[i] = m;
        }
        vector<vector<int>> edges(n, vector<int>());
        vector<int> ans;
        for (int i = 0; i < n - m + 1; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (target[i + j] == stamp[j])
                {
                    inDegree[i]--;
                    if (inDegree[i] == 0)
                    {
                        ans.push_back(i);
                    }
                }
                else
                {
                    edges[i + j].push_back(i);
                }
            }
        }
        bool matched[n];
        memset(matched, false, sizeof(matched));
        vector<int> res;
        while (!ans.empty())
        {
            int curr = ans.back();
            ans.pop_back();
            res.push_back(curr);
            for (int i = 0; i < m; ++i)
            {
                if (!matched[curr+i])
                {
                    matched[curr+i] = true;
                    for (int j : edges[curr+i])
                    {
                        inDegree[j]--;
                        if (inDegree[j] == 0)
                        {
                            ans.push_back(j);
                        }
                    }
                }
            }
        }
        if (res.size() == n - m + 1)
        {
            reverse(res.begin(), res.end());
            return res;
        }
        return {};
    }

};
// @lc code=end

