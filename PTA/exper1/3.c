LinkList Creat_LinkList() {
    LNode *p, *q, *head;
    int data;
    
    head = (LNode *)malloc(sizeof(LNode));
    if (head == NULL) {
        return NULL;
    }
    q = head;
    
    scanf("%d", &data);
    while (data != -1) {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = data;
        p->next = NULL;
        q->next = p;
        q = q->next;
        scanf("%d", &data);
    }
    
    return head;
}