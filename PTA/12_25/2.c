void LevelOrder(BiTree bt) {
    if (bt == NULL) {
        return;
    }

    BiTree queue[100];
    int rear = 0;
    int front = 0;

    queue[rear] = bt;
    rear++;

    while (front < rear) {
        printf("%3c", queue[front]->data);
        
        if (queue[front]->lchild) {
            queue[rear] = queue[front]->lchild;
            rear++; //push
        }
        if (queue[front]->rchild) {
            queue[rear] = queue[front]->rchild;
            rear++; //push
        }
        front++; //pop
    }    
}