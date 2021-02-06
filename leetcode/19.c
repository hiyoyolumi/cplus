给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//常规解法：先遍历一遍链表来确定链表的结点数量，再删除倒数第n个结点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *t,*q;
    int len,count;
    len = 1;
    count = 1;
    t = head;
    while(t->next != NULL)
    {
        len++;
        t = t->next;
    }
    t = head;
    while(t!=NULL)
    {
        if(n == len)
        {
            q = head;
            head = head->next;
            free(q);
            
            return head;
        }
        if(count == len-n)
        {
            q = t->next;
            t->next = t->next->next;
            free(q);

            return head;
        }
        t = t->next;
        count++;
    }
    return head;
}}
