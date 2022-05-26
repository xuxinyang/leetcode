/*
 * @lc app=leetcode.cn id=699 lang=cpp
 *
 * [699] 掉落的方块
 */

// @lc code=start
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> ret(n);
        map<int, int> heightMap;
        heightMap[0] = 0; // 初始时从 0 开始的所有点的堆叠高度都是 0
        for (int i = 0; i < n; i++) {
            int size = positions[i][1];
            int left = positions[i][0], right = positions[i][0] + positions[i][1] - 1;
            auto lp = heightMap.upper_bound(left), rp = heightMap.upper_bound(right);
            int rHeight = prev(rp)->second; // 记录 right + 1 对应的堆叠高度（如果 right + 1 不在 heightMap 中）

            // 更新第 i 个掉落的方块的堆叠高度
            int height = 0;
            for (auto p = prev(lp); p != rp; p++) {
                height = max(height, p->second + size);
            }

            // 清除 heightMap 中位于 (left, right] 内的点
            heightMap.erase(lp, rp);

            heightMap[left] = height; // 更新 left 的变化
            if (rp == heightMap.end() || rp->first != right + 1) { // 如果 right + 1 不在 heightMap 中，更新 right + 1 的变化
                heightMap[right + 1] = rHeight;
            }
            ret[i] = i > 0 ? max(ret[i - 1], height) : height;
        }
        return ret;
    }
};

// @lc code=end

