#include "HEAD.h"

//队列初始化
Queue *initQueue() {
    Queue *q;
    Time_data *p;

    q = (Queue *)malloc(sizeof(Queue));
    p = (Time_data *)malloc(sizeof(Time_data));  //这里的 p 是头结点
    p->next = NULL;
    q->head = q->front = q->rear = p;
    //初始化头结点编号为 0
    q->rear->serial_num = 0;
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
    Time_data *p;
    p = (Time_data *)malloc(sizeof(Time_data));

    //把传入的参数复制给分配的地址
    p->serial_num = data->serial_num;
    p->vip_status = data->vip_status;
    p->arrivd_time = data->arrivd_time;
    p->wait_time = data->wait_time;
    p->leave_time = data->leave_time;
    p->business_time = data->business_time;
    p->star_time = data->star_time;
    p->window_serial = data->window_serial;
    p->next = NULL;

    q->rear->next = p;
    q->rear = p;
}
//出队
//返回 1 成功， 0 失败
/**
 * @brief 在传统 出队 基础上，修改以下几点
 *        1. front 指针指向最新的头结点 而不是 始终指向头结点
 *
 * @param q
 * @return int
 */
int Out_Queue(Queue *q) {
    if (isEmpty(q)) {
        // TODO 感觉之后会在这里添东西
        printf("\n当前没有人排队\n");
        return 0;
    } else {
        //出队后 front 指向队头，出队的结点不会被释放
        q->front = q->front->next;
        if (q->front->next == NULL) {
            q->front = q->rear;
        }
        return 1;

        //出队后 front 仍指向头结点
        // Time_data *p;
        // p = q->front->next;
        // q->front->next = p->next;
        // free(p);
        // if (q->front->next == NULL) {
        //     q->rear = q->front;
        // }
        // return 1;
    }
}

void destory_queue(Queue *q) {
    Time_data *t;
    Time_data *p = q->head;
    while (p) {
        t = p;
        p = p->next;
        free(t);
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