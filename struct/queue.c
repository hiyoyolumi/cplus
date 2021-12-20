#include "HEAD.h"

typedef struct Node {
    int arrivd_time;    //到达时间
    int wait_time;      //等待时间
    int leave_time;     //离开时间
    int business_time;  //办理业务时间
    int star_time;      //开始办理时间
    struct Node *next;
} Time_data;

typedef struct Queue {
    Time_data *front;   //始终指向头结点
    Time_data *rear;
} Queue;

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