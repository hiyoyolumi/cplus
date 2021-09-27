LNode *Get_LinkList(LinkList L, int i) {
    int n = 1;
    LNode *p = L->next;
    if (i == 0) {
        return L;
    } else if (i < 0) {
        return NULL;
    }
    
    while (p && (n != i)) {
        p = p->next;
        n++;
    }
    
    if (n != i) {
        return NULL;
    }
    
    return p;
}