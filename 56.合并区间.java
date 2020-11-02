import java.util.ArrayList;
import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=56 lang=java
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (43.24%)
 * Likes:    672
 * Dislikes: 0
 * Total Accepted:    158.9K
 * Total Submissions: 367.6K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: intervals = [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * intervals[i][0] <= intervals[i][1]
 * 
 * 
 */

// @lc code=start
class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });

        ArrayList<int[]> outputs = new ArrayList<>();
        for (int i = 0; i < intervals.length; i++) {
            int[] currInterval = intervals[i];
            if ((outputs.isEmpty()) ||
                (outputs.get(outputs.size() - 1)[1] < currInterval[0])) {
                outputs.add(currInterval);
            } else {
                int newLastRight = Math.max(outputs.get(outputs.size() - 1)[1], currInterval[0]);
                outputs.get(outputs.size() - 1)[1] = newLastRight;
            }
        }

        return outputs.toArray(new int[outputs.size()][]);
    }
}
// @lc code=end