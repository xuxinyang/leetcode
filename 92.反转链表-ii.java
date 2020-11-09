/*
 * @lc app=leetcode.cn id=92 lang=java
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (51.63%)
 * Likes:    573
 * Dislikes: 0
 * Total Accepted:    83.7K
 * Total Submissions: 162.1K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {

        /* Head is empty or m == n, do nothing */
        if (head == null || m == n) {
            return head;
        }

        ListNode dummy = new ListNode(0);
        int changeNode = n - m;
        dummy.next = head;
        ListNode currentPrev = dummy, currentTail = head, currentNext = head;

        /* Flag previous node position of m and m+1 */
        while (currentTail.next != null && m > 1) {
            currentPrev = currentTail;
            currentTail = currentTail.next;
            m--;
        }

        /* Swap the node from m to n */
        while (changeNode > 0) {
            currentNext = currentTail.next;
            currentTail.next = currentNext.next;
            currentNext.next = currentPrev.next;
            currentPrev.next = currentNext;
            changeNode--;
        }

        return dummy.next;
    }
}
// @lc code=end

