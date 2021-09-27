int Insert_LinkList(LinkList L, int i, datatype x) {
    LNode *p, *t;
    
//     p = Get_LinkList(L, i - 1);
    p = L;
    int n = 0;
    while (p && (i - 1 != n)) {
        p = p->next;
        n++;
    }
    if (p != NULL) {
        t = (LNode *)malloc(sizeof(LNode));
        t->next = p->next;
        p->next = t;
        t->data = x;
        return 1;
    } else {
        return 0;
    }
}