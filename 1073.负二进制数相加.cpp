/*
 * @lc app=leetcode.cn id=1073 lang=cpp
 *
 * [1073] 负二进制数相加
 */

// @lc code=start

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n = max(n1,n2)+4;
        vector<int> res(n, 0);
        // 和arr1和arr2 倒序的计算，低位在前面
        for (int i = n1-1; i >= 0; --i)
        {
            res[n1-1-i] += arr1[i];
        }
        for (int i = n2-1; i >= 0; --i)
        {
            res[n2-1-i] += arr2[i];
        }

        // 从低位开始计算
        for (int i = 0; i +2 < n; ++i)
        {
            // 进位
            int carry = res[i] >> 1;
            res[i] &= 1;
            res[i+1] += carry;
            res[i+2] += carry;
        }
        // 观察最高位连续零需要移除
        int k = n-3;
        // 这里结束是0，来避免0,0->空的情况
        while (k > 0 && res[k] == 0)
        {
            --k;
        }
        reverse(res.begin(), res.begin()+k+1);
        // 移除末尾的为0的部分
        int i = n-k-1;
        while(i > 0)
        {
            --i;
            res.pop_back();
        }

        return res;
    }
};
// @lc code=end

