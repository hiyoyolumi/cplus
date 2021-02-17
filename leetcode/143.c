给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//这道题目只需要分为 步，就可以解决
//第一步，把这段链表分成两段
//第二步，把后一段链表逆置
//第三步，将链表合并

struct ListNode* midnode(struct ListNode *head)
{
    struct ListNode *p, *q;
    p = head;
    q = head;
    while(p->next && p->next->next)
    {
        p = p->next->next;
        q = q->next;
    }
    return q;
}

struct ListNode* reserve(struct ListNode *head)
{
    struct ListNode *p,*q,*r;
    p = head;
    r = NULL;
    while(p)
    {
        q = p->next;
        p->next = r;
        r = p;
        p = q;
    }
    return r;
}

void reorderList(struct ListNode* head){
    if(!head || !head->next)
    {
        return head;
    }
    struct ListNode *mid, *righthead, *head2, *p, *q, *temp1, *temp2;
    mid = midnode(head);
    righthead = mid->next;
    mid->next = NULL;
    head2 = reserve(righthead);
    p = head;
    q = head2;
    while(p && q)
    {
        temp1 = p->next;
        temp2 = q->next;
        p->next = q;
        p = temp1;
        q->next = p;
        q = temp2;
    }
}
