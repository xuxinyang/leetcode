/*
 * @lc app=leetcode.cn id=857 lang=cpp
 *
 * [857] 雇佣 K 名工人的最低成本
 */

// @lc code=start
class Worker
{
public:
    int quality{0};
    int wage{0};
    double ratio{0.0f};

    bool operator<(const Worker &other)
    {
        return this->ratio < other.ratio;
    }

    double GetRatio() const
    {
        if (quality == 0) {
            return 0;
        }
        return wage * 1.0 / quality;
    }
};

class Solution {
public:
    /*
    * 总体思想：假设wage / qualit为性价比，先按照性价比对工人进行排序
    *           每次总有一个工人拿到他的期望工资，假设某一个工人拿到期望工资的情况下，其他工人的性价比需要比这个工人小才能拿到
    *           他所期望的工资
    *           依次假设每个工人拿到期望工资的情况下在其他工人中挑选k - 1个工人组成答案
    *           假如满足性价比条件的工人多于k - 1个，优先选择质量较差的(质量较差的cost相对也较小)
    */
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        size_t n = quality.size();

        vector<Worker> wokers(n);
        for (size_t i = 0; i < n; ++i) {
            wokers[i].quality = quality[i];
            wokers[i].wage = wage[i];
            wokers[i].ratio = wage[i] * 1.0 / quality[i];
        }       
        sort(wokers.begin(), wokers.end());

        double res = INT32_MAX;
        int total = 0;
        // 默认是大顶堆，需要改为使用小顶堆
        priority_queue<int, vector<int>, greater<int>> qualityQueue;
        for (auto &wker : wokers) {
            qualityQueue.push(-wker.quality);
            total += wker.quality;
            if (qualityQueue.size() > k) {
                total += qualityQueue.top();
                qualityQueue.pop();
            }
            if (qualityQueue.size() == k) {
                res = min(res, total * wker.GetRatio());
            }
        }

        return res;
    }
};
// @lc code=end

