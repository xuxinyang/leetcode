/*
 * @lc app=leetcode.cn id=826 lang=cpp
 *
 * [826] 安排工作以达到最大收益
 */

// @lc code=start
class Solution {
public:

    typedef struct {
        int profit;
        int diff;
    } St;

    static bool cmp(const St &a, const St &b) {
        if(a.profit != b.profit) {
            return a.profit > b.profit;
        }
        return a.diff < b.diff;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = (int)difficulty.size();

        vector<St> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = St{profit[i], difficulty[i]};
        }

        sort(v.begin(), v.end(), cmp);

        sort(worker.begin(), worker.end(), greater<int>());

        int sum = 0, idx = 0;
        for(int i : worker) {
            while(idx < n && v[idx].diff > i) {
                idx ++;
            }
            if(idx == n) {
                break;
            }
            sum += v[idx].profit;
        }

        return sum;
    }
};
// @lc code=end

