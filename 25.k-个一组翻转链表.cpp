/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* next = head->next;
        int count = 0;
        while (next) {
            count++;
            if (count == k) {
                pre = reverse(pre, cur);
                count = 0;
            }
            pre = cur;
            cur = next;
            next = next->next;
        }
        if (count == k) {
            pre = reverse(pre, cur);
        }
        return dummy->next;
    }
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        ListNode* next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        return next;
    }
    
};
// @lc code=end

