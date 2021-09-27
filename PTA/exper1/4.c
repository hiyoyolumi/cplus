int Length_LinkList(LinkList L) {
    LNode *p = L->next;
    int num = 0;
    
    while (p) {
        num ++;
        p = p->next;
    }
    
    return num;
}