/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenOfA = 0, lenOfB = 0, skiNodeNum = 0;
        ListNode *pa = headA, *pb = headB;

        /* 计算A链表的长度 */
        while(pa != nullptr)
        {
            lenOfA++;
            pa = pa->next;
        }

        /* 计算B链表的长度 */
        while(pb != nullptr)
        {
            lenOfB++;
            pb = pb->next;
        }

        if(lenOfA >= lenOfB)
        {
            skiNodeNum = lenOfA - lenOfB;
            while(skiNodeNum > 0 && headA != nullptr)
            {
                headA = headA->next;
                skiNodeNum--;
            }
        }
        else
        {
            skiNodeNum = lenOfB - lenOfA;
            while(skiNodeNum > 0 && headB != nullptr)
            {
                headB = headB->next;
                skiNodeNum--;
            }
        }

        while(headA != headB && headA != nullptr && headB != nullptr)
        {
            headA = headA->next;
            headB = headB->next;
        }

        if(headA != nullptr)
        {
            return headA;
        }
        else
        {
            return nullptr;
        }
    }
};
// @lc code=end

