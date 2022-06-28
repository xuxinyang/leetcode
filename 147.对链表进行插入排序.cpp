/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = head;
        while(cur){
            ListNode* next = cur->next;
            ListNode* pre = dummy;
            while(pre->next && pre->next->val < cur->val){
                pre = pre->next;
            }
            cur->next = pre->next;
            pre->next = cur;
            cur = next;
        }
        return dummy->next;
    }
};
// @lc code=end

