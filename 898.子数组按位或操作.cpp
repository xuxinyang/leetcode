/*
 * @lc app=leetcode.cn id=898 lang=cpp
 *
 * [898] 子数组按位或操作
 */

// @lc code=start
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int N = A.size();
        std::unordered_set<int> S;
        if (N < 2) return N;

        for (int i = 0; i < N; ++ i){
            S.insert(A[i]);
            for (int j = i - 1; j >= 0; -- j){
                if ((A[j] | A[i]) == A[j]) break;
                A[j] |= A[i];
                S.insert(A[j]);
            }
        }

        return S.size();
    }
};
// @lc code=end

