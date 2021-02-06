请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//这道题目的基本思路就是直接创建一个新的链表
//通过头插的方式来将整个链表逆置
//然后一一进行比对得出结果

bool isPalindrome(struct ListNode* head){
        struct ListNode *head0,*p,*t;
    struct ListNode *a,*b;
    int count=0,len=0;
    head0 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head0->next = NULL;
    t = head;
    while(t)			//头插法创建链表
    {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = t->val;
        p->next = head0->next;
        head0->next = p;
        t = t->next;
        len++;
    }
    a = head;
    b = head0->next;
    while(a)			//一一比对
    {
        if(a->val == b->val)
        {
            count++;
        }
        else
        {
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return true;
}
