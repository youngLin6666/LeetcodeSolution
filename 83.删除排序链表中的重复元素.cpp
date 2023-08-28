/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        /* 双指针法 */
        if(head == NULL)
        {
            return head;
        }
        else if(head->next == NULL)
        {
            return head;
        }

        ListNode *slow = head, *fast = head->next, *p = NULL;

        while(fast != NULL)
        {
            if(fast->val == slow->val) /* 删除节点 */
            {
                p = fast;

                /* 断开删除节点 */
                slow->next = fast->next;
                fast = fast->next;
                p->next = NULL;

                delete p;
            }
            else{
                slow = fast;
                fast = fast->next;
            }
        }
        
        return head;
    }
};
// @lc code=end

