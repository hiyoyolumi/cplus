#include "HEAD.h"

//队列初始化
Queue *initQueue() {
    Queue *q;
    Time_data *p;

    q = (Queue *)malloc(sizeof(Queue));
    p = (Time_data *)malloc(sizeof(Time_data));
    p->next = NULL;
    q->front = q->rear = p;
    if (!q->front) {
        return NULL;
    }
    return q;
}
//判断队空
int isEmpty(Queue *q) {
    if (q->front == q->rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}
//入队
void Enqueue(Queue *q, Time_data *data) {
    Time_data * p;
    p = (Time_data *)malloc(sizeof(Time_data));

    p->arrivd_time = data->arrivd_time;
    p->wait_time = data->wait_time;
    p->leave_time = data->leave_time;
    p->business_time = data->business_time;
    p->star_time = data->star_time;

    q->rear->next = p;
    q->rear = p;
}
//出队
//返回 1 成功， 0 失败
int Out_Queue(Queue *q) {
    if (isEmpty(q)) {
        printf("当前该窗口没有人！！\n");
        return 0;
    } else {
        Time_data *p;
        p = q->front->next;
        q->front->next = p->next;
        free(p);
        if (q->front->next == NULL) {
            q->rear = q->front;
        }
        return 1;
    }
}

int get_Queue_num(Queue *q) {
    int num = 0;
    Time_data *t;
    t = q->front;
    while (t->next) {
        num++;
        t = t->next;
    }
    return num;
}