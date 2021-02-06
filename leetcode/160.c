编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表：



在节点 c1 开始相交。


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//这道题目用到了双指针
//思路说明：a+c+b == b+c+a
//意思就是让 p走到尽头后开始走q的路，q也一样
//那么如果两个链表相交的话，p和q走过了相同路程之后就会相交
//如果两个链表不相交的话则返回NULL

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p,*q;
    p = headA;
    q = headB;
    while(q!=p)
    {
        p = p==NULL? headB:p->next;
        q = q==NULL? headA:q->next;
    }
    return p;
}

//解释一下返回NULL的情况
//如果两个链表不相交的话，那么会同时走完全部的路程，然后都指向空
//这个时候返回的值就是NULL
