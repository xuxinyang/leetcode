import java.util.LinkedList;

/*
 * @lc app=leetcode.cn id=57 lang=java
 *
 * [57] 插入区间
 *
 * https://leetcode-cn.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (38.01%)
 * Likes:    219
 * Dislikes: 0
 * Total Accepted:    33K
 * Total Submissions: 86.8K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
 * 
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
 * 输出：[[1,5],[6,9]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * 输出：[[1,2],[3,10],[12,16]]
 * 解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 * 
 * 
 * 
 * 
 * 注意：输入类型已在 2019 年 4 月 15 日更改。请重置为默认代码定义以获取新的方法签名。
 * 
 */

// @lc code=start
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        // init data
        int newStart = newInterval[0], newEnd = newInterval[1];
        int index = 0, n = intervals.length;
        LinkedList<int[]> output = new LinkedList<int[]>();

        // add all intervals starting before newInterval
        while (index < n && newStart > intervals[index][0]) {
            output.add(intervals[index++]);
        }

        // add new intervals
        int[] interval = new int[2];
        // if there is an overlap, just add the interval
        if (output.isEmpty() || output.getLast()[1] < newStart) {
            output.add(newInterval);
        } else {
            interval = output.removeLast();
            interval[1] = Math.max(interval[1], newEnd);
            output.add(interval);
        }
        // add next intervals, merge with newInterval if needed
        while (index < n) {
            interval = intervals[index++];
            int start = interval[0], end = interval[1];
            // if there is no overlap, just add an intervals
            if (output.getLast()[1] < start) {
                output.add(interval);
            } else {
                interval = output.removeLast();
                interval[1] = Math.max(interval[1], end);
                output.add(interval);
            }
        }

        return output.toArray(new int[output.size()][2]);
    }
}
// @lc code=end

