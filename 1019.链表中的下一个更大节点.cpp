/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
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
    vector<int> nextLargerNodes(ListNode *head)
    {
        int count = 0; //计数，作为下标
        vector<int> result;
        stack<pair<int, int>> tmp; //first为val，second为下标
        while (head)
        {
            result.push_back(0); //给result数组后面+0，1为保证长度，2是默认值（后无更大的值的话）为0
            while (!tmp.empty() &&
                   head->val > tmp.top().first) //栈不为空且head指针的val值大于栈顶的元素的值
            {
                result[tmp.top().second] = head->val; //result数组修改，满足题意要求的最大值，然后出栈，继续循环
                tmp.pop();
            }
            tmp.push(make_pair(head->val, count++)); //count++计数
            head = head->next; //下一个节点
        }
        return result;
    }
};
// @lc code=end

