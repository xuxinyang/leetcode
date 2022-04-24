/*
 * @lc app=leetcode.cn id=1898 lang=cpp
 *
 * [1898] 可移除字符的最大数目
 */

// @lc code=start
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int ns = s.size();
        int np = p.size();
        int n = removable.size();
        // 辅助函数，用来判断移除 k 个下标后 p 是否是 s_k 的子序列
        auto check = [&](int k) -> bool {
            vector<int> state(ns, 1);   // s 中每个字符的状态
            for (int i = 0; i < k; ++i){
                state[removable[i]] = 0;
            }
            // 匹配 s_k 与 p 
            int j = 0;
            for (int i = 0; i < ns; ++i){
                // s[i] 未被删除且与 p[j] 相等时，匹配成功，增加 j
                if (state[i] && s[i] == p[j]){
                    ++j;
                    if (j == np){
                        return true;
                    }
                }
            }
            return false;
        };

        // 二分查找
        int l = 0;
        int r = n + 1;
        while (l < r){
            int mid = l + (r - l) / 2;
            if (check(mid)){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l - 1;

    }
};
// @lc code=end

