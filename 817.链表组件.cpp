/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
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
    int numComponents(ListNode* head, vector<int>& nums) {
       int hash[10010];//用哈希表统计nums数组里的元素
       memset(hash,0,sizeof(hash));
       for(int i=0;i<nums.size();++i)
       ++hash[nums[i]]; 
        int ans=0;
        int pre=0;//统计最长连续节点的存在
        while(head){
            if(hash[head->val]){
                pre=1;
            }
            else{
                if(pre)++ans;
                pre=0;
            }
            head=head->next;
        }
        if(pre)++ans;//判断不存在nums数组里的值在链表中间的情况
        return ans;

    }
};
// @lc code=end

