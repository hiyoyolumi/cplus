将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例1：
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]

示例 2：
输入：l1 = [], l2 = []
输出：[]

示例 3：
输入：l1 = [], l2 = [0]
输出：[0]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//迭代
//先创建一个头结点，使得哨兵结点向后移动的操作一致
//当 l1 和 l2 都不是空链表时，判断 l1 和 l2 哪一个链表的头节点的值更小，将较小值的节点添加到结果里，当一个节点//被添加到结果里之后，将对应链表中的节点向后移一位。

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *pre,*head;
    if(!l1)
    {
        return l2;
    }
    else if(!l2)
    {
        return l1;
    }
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    pre = head;
    do
    {
        if(!l1 || !l2)
        {
            pre->next = l1==NULL ? l2 : l1;
            return head->next;
        }
        if(l1->val < l2->val)
        {
            pre->next = l1;
            pre = l1;
            l1 = l1->next;
        }
        else
        {
            pre->next = l2;
            pre = l2;
            l2 = l2->next;
        }
    } while(pre);

    return head->next;
}
