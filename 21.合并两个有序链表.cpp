/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        else if(list1 == nullptr)
        {
            return list2;
        }
        else if(list2 == nullptr)
        {
            return list1;
        }

        ListNode* p = list1, *q = list2, *head = nullptr, *tail = nullptr;
        if(p->val < q->val)
        {
            head = p;
            tail = p;
            p = p->next;
            tail->next = nullptr;
        }
        else
        {
            head = q;
            tail = q;
            q = q->next;
            tail->next = nullptr;

        }       

        while(p != nullptr && q != nullptr)
        {
            if(p->val < q->val)
            {
                tail->next = p;
                tail = tail->next;
                p = p->next;
                tail->next = NULL;
            }
            else
            {
                tail->next = q;
                tail = tail->next;
                q = q->next;
                tail->next = NULL;
            }
        }

        if(p != nullptr)
        {
            tail->next = p;
        }
        else
        {
            tail->next = q;
        }

        return head;
    }
};
// @lc code=end

