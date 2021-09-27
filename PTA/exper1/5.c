LNode *Locate_LinkList(LinkList L, datatype x) {
    LNode *p = L->next;
    
    while (p) {
        if (p->data == x) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}