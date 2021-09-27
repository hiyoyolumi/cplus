LinkList Creat_LinkList()
{
    LNode *head, *p;
    head = (LNode *)malloc(sizeof(LNode));
    head->next = NULL;
    int n;
    scanf("%d", &n);
    while (n != -1) {
        p = (LNode *)malloc(sizeof(LNode));
        p->next = head->next;
        p->data = n;
        head->next = p;
        scanf("%d", &n);
    }
    head->data = -1;
    
    return head;
}