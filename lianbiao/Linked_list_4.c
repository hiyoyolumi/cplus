/* 双向循环链表 */

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prior;
}node;

void Create(node **head,node **wear);
void print_Double(node *head,node *wear);
int Node_Number(node *head);
void List_Insert_head(node *head);
void List_Insert_tail(node *head,node **wear);
void List_Delect_k(node *head,node **wear);
void List_Delect_key(node *head,node **wear);
void List_Change_Data(node *head);
void List_Find_k(node *head);
void List_Find_key(node *head);

int main()
{
    node *head,*wear;
    Create(&head,&wear);
    print_Double(head,wear);
    List_Insert_head(head);
    print_Double(head,wear);
    List_Insert_tail(head,&wear);
    print_Double(head,wear);
    List_Delect_k(head,&wear);
    print_Double(head,wear);
    List_Delect_key(head,&wear);
    print_Double(head,wear);
    List_Change_Data(head);
    print_Double(head,wear);
    List_Find_k(head);
    List_Find_key(head);
}

void List_Insert_head(node *head)
{
    node *t;
    int b;
    t = head;
    printf("Input the number you want to Insert in the LinkedList's head:");
    scanf("%d", &b);
    t = (node *)malloc(sizeof(node));
    t->data = b;
    t->next = head->next;
    t->prior = head;
    t->next->prior = t;
    head->next = t;
    return;
}

void List_Insert_tail(node *head,node **wear)
{
    node *t;
    int b;
    printf("Input the number you want to Insert in the LinkedList's tail:");
    scanf("%d", &b);
    t = (node *)malloc(sizeof(node));
    t->data = b;
    t->next = head;
    t->prior = (*wear);
    (*wear)->next = t;
    (*wear) = t;
    head->prior = (*wear);
    return;
}

void List_Delect_k(node *head,node **wear)
{
    node *t,*q;
    int k, count=1;
    t = head;
    printf("Input the sequence number of the LinkedList you want to Delect:");
    scanf("%d", &k);
    if(k>Node_Number(head) || k<=0)
    {
        printf("FALSE\n");
        return;
    }
    do
    {
        if(count == k)
        {
            q = t->next;
            t->next = t->next->next;
            t->next->prior = t;
            if(t->next == head)
            {
                (*wear) = t;
            }
            free(q);
            return;
        }
        t = t->next;
        count++;
    } while (t!=head);
}

void List_Delect_key(node *head,node **wear)
{
    node *t,*q;
    int key,sum=0;
    t = head;
    printf("Input the number of the LinkedList you want to Delect:");
    scanf("%d", &key);
    do
    {
        cc:
        if(t->next->data == key)
        {
            q = t->next;
            t->next = t->next->next;
            t->next->prior = t;
            sum++;
            if(t->next == head)
            {
                (*wear) = t;
                free(q);
                return;
            }
            free(q);
            goto cc;            //这里使用goto语句，防止链表第一个元素被删除后无法通过while的条件判断
            //continue;           使用continue会使链表第一个元素被删除后无法进入迭代
        }
        t = t->next;
    } while (t!=head);
    if(sum == 0)
    {
        printf("NOT FOUND KEY\n");
    }
}

void List_Change_Data(node *head)
{
    node *t;
    int k,count=1,num;
    t = head->next;
    printf("Input the sequence number of the LinkedList you want to Change:");
    scanf("%d", &k);
    if(k>Node_Number(head) || k<=0)
    {
        printf("FALSE\n");
        return;
    }
    while(t!=head)
    {
        if(count == k)
        {
            printf("Input the number you want to have in the %d\'th node:", k);
            scanf("%d", &num);
            t->data = num;
            return;
        }
        t = t->next;
        count++;
    }
}

void List_Find_k(node *head)
{
    node *t;
    int k, count=1;
    t = head->next;
    printf("Input the sequence number of the LinkedList you want to find:");
    scanf("%d", &k);
    if(k>Node_Number(head) || k<=0)
    {
        printf("FALSE\n");
        return;
    }
    while(t!=head)
    {
        if(count == k)
        {
            printf("The %d'th element's data is %d\n", k, t->data);
            return;
        }
        t = t->next;
        count++;
    }
}

void List_Find_key(node *head)
{
    node *t;
    int key,count=1,sum=0;
    t = head->next;
    printf("Input the number of the LinkedList you want to Find:");
    scanf("%d", &key);
    printf("The sequence number of key is:");
    while(t!=head)
    {
        if(t->data == key)
        {
            printf("%d ", count);
            sum++;
        }
        t = t->next;
        count++;
    }
    if(sum == 0)
    {
        printf("NOT FIND KEY");
    }
    printf("\n");
    return;
}

void Create(node **head,node **wear)
{
    node *t,*q;
    int n,b;
    (*head) = (node *)malloc(sizeof(node));
    (*head)->next = (*head);
    (*head)->prior = (*head);
    q = (*head);
    printf("Input the amount of the LinkedList you want to have:");
    scanf("%d", &n);
    if(n<=0)
    {
        printf("FALSE\n");
        return;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d", &b);
        t = (node *)malloc(sizeof(node));
        t->data = b;
        t->next = (*head);
        t->prior = q;
        q->next = t;
        (*head)->prior = t;
        q = t;
    }
    (*wear) = t;
    return;
}

void print_Double(node *head,node *wear)
{
    node *t;
    t = head->next;
    while(t!=head)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
    t = wear;
    while(t!=head)
    {
        printf("%d ", t->data);
        t = t->prior;
    }
    printf("\n");
    return;
}

int Node_Number(node *head)
{
    node *t;
    t = head->next;
    int num=0;
    while(t!=head)
    {
        t = t->next;
        num++;
    }
    return num;
}
