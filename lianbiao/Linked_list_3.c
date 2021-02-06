/* 双向链表 */

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prior;
}node;

void List_Insert_head(node *head);
void List_Insert_tail(node **wear);
void List_Delect_k(node *head,node **wear);
void List_Delect_key(node *head,node **wear);
void List_Change_Data(node *head);
void List_Find_k(node *head);
void List_Find_key(node *head);
void Create(node **head,node **wear);   //创建双向链表
void print(node *head);
void print_Double(node *head,node *wear);  //反向输出，检验前驱指针的正确性
int Node_number(node *head);

int main()
{
    node *head,*wear;
    Create(&head, &wear);
    print_Double(head,wear);
    List_Insert_head(head);
    print_Double(head,wear);
    List_Insert_tail(&wear);
    print_Double(head,wear);
    List_Delect_k(head,&wear);
    print_Double(head,wear);
    List_Delect_key(head,&wear);
    print_Double(head,wear);
    List_Change_Data(head);
    print_Double(head,wear);
    List_Find_k(head);
    //print_Double(head,wear);
}

void List_Insert_head(node *head)
{
    node *p;
    int b;
    printf("Input the number which you want to Insert in the LinkedList\'s head:");
    scanf("%d", &b);
    p = (node *)malloc(sizeof(node));
    p->data = b;
    p->next = head->next;
    p->prior = head;
    p->next->prior = p;
    head->next = p;
    return;
}

void List_Insert_tail(node **wear)
{
    node *p;
    int b;
    printf("Insert the number which you want to Insert in the LinkedList\'s tail:");
    scanf("%d", &b);
    p = (node *)malloc(sizeof(node));
    p->data = b;
    p->next = NULL;
    p->prior = *wear;
    (*wear)->next = p;
    (*wear) = p;
    return;
}

void List_Delect_k(node *head,node **wear)
{
    node *t,*q;
    int k,count=1;
    printf("Input the sequence number of the LinkedList you want to Delect:");
    scanf("%d", &k);
    if(k>Node_number(head) || k<=0)
    {
        printf("FALSE\n");
        return;
    }
    t = head;
    if(k == Node_number(head))          //当要删除的结点是链表的最后一个时，要特殊考虑
    {
        q = (*wear);
        (*wear) = (*wear)->prior;
        (*wear)->next = NULL;
        free(q);
        return;
    }
    while(t)
    {
        if(count == k)
        {
            q = t->next;
            t->next = t->next->next;
            t->next->prior = t;
            free(q);
            return;
        }
        count++;
        t = t->next;
    }
}

void List_Delect_key(node *head,node **wear)
{
    node *t,*q;
    int key,count=0;
    t = head;
    printf("Input the number of the LinkedList you want to Delect:");
    scanf("%d", &key);
    do                                      //这里必须用do_while语句，以此来避免第一个if判断条件中的指向空的指针
    {
        if(t->next->data == key)
        {
            q = t->next;
            t->next = t->next->next;
            if(!t->next)                    //双向链表必须要注意删除最后一个结点的特殊情况
            {
                (*wear) = (*wear)->prior;
                free(q);
                count++;
                break;
            }
            t->next->prior = t;
            free(q);
            count++;
            continue;
        }
        t = t->next;
    } while(t->next);
    if(count == 0)
    {
        printf("NOT FONUD KEY");
    }
    return;
}

void List_Change_Data(node *head)
{
    node *t;
    int k,count=1,num;
    t = head->next;
    printf("Input the sequence number of the LinkedList you want to Change:");
    scanf("%d", &k);
    if(k>Node_number(head) || k<=0)
    {
        printf("FALSE\n");
        return;
    }
    while(t)
    {
        if(count == k)
        {
            printf("Input the number you want to have in the %d\'th node:", k);
            scanf("%d", &num);
            t->data = num;
            break;
        }
        t = t->next;
        count++;
    }
}

void List_Find_k(node *head)
{
    node *t;
    int k,count=1;
    t = head->next;
    printf("Input the sequence number of the LinkedList you want to Find:");
    scanf("%d", &k);
    if(k>Node_number(head) || k<=0)
    {
        printf("FALSE\n");
        return;
    }
    while(t)
    {
        if(count == k)
        {
            printf("%d\n", t->data);
            return;
        }
        t = t->next;
        count++;
    }
}

void List_Find_key(node *head)
{
    node *t;
    int key,sum=0,count=1;
    t = head->next;
    printf("Input the number of the LinkedList you want to find:");
    scanf("%d", &key);
    while(t)
    {
        if(t->data == key)
        {
            printf("%d", count);
            sum++;
        }
        t = t->next;
        count++;
    }
    if(sum == 0)
    {
        printf("NOT FONUD KEY\n");
    }
    return;
}

void Create(node **head, node **wear)
{
    node *p,*q,*r;
    int n,b;
    *head = (node *)malloc(sizeof(node));
    (*head)->next = NULL;
    (*head)->prior = NULL;
    q = *head;
    r = *head;
    printf("Input the amount of the LinkedList:");
    scanf("%d", &n);
    if(n<=0)
    {
        printf("FALSE");
        return;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d", &b);
        p = (node *)malloc(sizeof(node));
        p->data = b;
        p->next = NULL;
        p->prior = q;
        q->next = p;
        q = p;
    }
    (*wear) = p;
    return;
}

void print(node *head)
{
    node *t;
    t = head->next;
    while(t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

void print_Double(node *head, node *wear)
{
    node *t;
    t = head->next;
    while(t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
    t = wear;
    while(t != head)
    {
        printf("%d ", t->data);
        t = t->prior;
    }
    printf("\n");
}

int Node_number(node *head)
{
    node *t;
    int count=0;
    t = head->next;
    while(t)
    {
        t = t->next;
        count++;
    }
    return count;
}
