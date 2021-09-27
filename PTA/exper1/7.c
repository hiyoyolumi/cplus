int Del_LinkList(LinkList L, int i) {
    if (i <= 0) {
        printf("NOT");
        return 0;
    }
    LNode *p, *q;
    p = L->next;
    int num = 0;
    while (p) {
        num++;
        p = p->next;
    }
    if (i > num) {
        printf("Node %d do not exist", i);
        return 0;
    }
    
    p = Get_LinkList(L, i - 1);
    if (p != NULL) {
        q = p->next;
        p->next = q->next;
        free(q);
        return 1;
    } else {
        return 0;
    }
}