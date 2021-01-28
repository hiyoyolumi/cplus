#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void Create(struct ListNode **head);
void print(struct ListNode *head);
struct ListNode* partition(struct ListNode *head, int x);

int main()
{
    struct ListNode *head;
    int x;
    Create(&head);
    print(head);
    scanf("%d", &x);
    head = partition(head, x);
    print(head);
}

struct ListNode* partition(struct ListNode *head, int x)
{
    struct ListNode *smallhead,*largehead,*t,*small,*large;
    smallhead = (struct ListNode *)malloc(sizeof(struct ListNode));
    largehead = (struct ListNode *)malloc(sizeof(struct ListNode));
    smallhead->next = NULL;
    largehead->next = NULL;
    small = smallhead;
    large = largehead;
    t = head->next;
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

    return smallhead;
}

void Create(struct ListNode **head)
{
    struct ListNode *p,*q;
    int n,b;
    *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    (*head)->next = NULL;
    q = *head;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &b);
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = b;
        p->next = NULL;
        q->next = p;
        q = p;
    }

    return;
}

void print(struct ListNode *head)
{
    struct ListNode *t;
    t = head->next;
    while(t)
    {
        printf("%d ", t->val);
        t = t->next;
    }
    printf("\n");
}