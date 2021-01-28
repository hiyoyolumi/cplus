#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* Create();
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
void print(struct ListNode *head);

int main()
{
    struct ListNode *head;
    int n;
    head = Create();
    scanf("%d", &n);
    head = removeNthFromEnd(head, n);
    print(head);
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
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
}

struct ListNode* Create()
{
    struct ListNode *p,*q,*head;
    int n,b;
    head = NULL;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &b);
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = b;
        p->next = NULL;
        if(head == NULL)
        {
            head = p;
        }
        else
        {
            q->next = p;
        }
        q = p;
    }
    return head;
}

void print(struct ListNode *head)
{
    while(head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}