删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//这个题目比较简单，就是基本的链表操作
//但是需要注意避免指向空的指针

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *p,*head0;
    head0 = (struct ListNode *)malloc(sizeof(struct ListNode));		//创建一个头结点，方便删除操作
    head0->next = head;
    p = head0;
    do
    {
        if(p->next && p->next->val == val)	//这里的p->next目的是避免指向空的指针
        {
            p->next = p->next->next;
            continue;
        }
        p = p->next;
    } while(p);
    return head0->next;				//返回头结点
}
