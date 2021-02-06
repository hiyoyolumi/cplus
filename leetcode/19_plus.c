给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//使用双指针
//基本思路为：先将第一个指针向后移动n次，这样做的目的为创造两个指针之间的间隔

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p,*q;
    p = head;
    q = head;
    for(int i=0;i<n;i++)	//第一步
    {
        p = p->next;
    }
    if(!p)			//如果移动完之后p指向空的话，说明要删除的结点是第一个结点
    {				//那么删除掉第一个结点并返回新的头结点
        return head->next;	
    }
    while(p->next)		//当p的后继指针指向空的时候，q的后继指针指向的结点即为要删除的结点
    {
        p = p->next;
        q = q->next;
    }
    q->next = q->next->next;	//执行删除操作

    return head;
}
