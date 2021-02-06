给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例：

输入：head = 1->4->3->2->5->2, x = 3
输出：1->2->2->4->3->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//这道题目的题目描述有点难懂
//其实就是要新建两个链表，小于特定值的放在一个链表里，大于特定值的放到另一个链表里
//最后将两个链表合并

struct ListNode* partition(struct ListNode* head, int x){

    struct ListNode *smallhead,*largehead,*t,*small,*large;
    smallhead = (struct ListNode *)malloc(sizeof(struct ListNode));
    largehead = (struct ListNode *)malloc(sizeof(struct ListNode));
    smallhead->next = NULL;
    largehead->next = NULL;
    small = smallhead;
    large = largehead;
    t = head;
    while(t)
    {
        if(t->val < x)
        {
            small->next = t;
            small = t;
        }
        else
        {
            large->next = t;
            large = t;
        }
        t = t->next;
    }
    small->next = largehead->next;
    large->next = NULL;

    return smallhead->next;
}
