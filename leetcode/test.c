#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 1024
typedef int datatype;
typedef struct
{
    datatype data[MAXSIZE]; /*数据的存储区*/
    int front, rear;        /*队头队尾指针*/
    int num;                /*队中元素的个数*/
} c_SeQueue;                /*循环队*/

c_SeQueue *Init_SeQueue();                  /*这里省略函数实现代码*/
int In_SeQueue(c_SeQueue *q, datatype x);   /*这里省略函数实现代码*/
int Out_SeQueue(c_SeQueue *q, datatype *x); /*这里省略函数实现代码*/
int Empty_SeQueue(c_SeQueue *q);            /*这里省略函数实现代码*/

int Partition(datatype a[], int first, int last);  /*这里省略函数实现代码*/
void QuickSort(datatype a[], int first, int last); /*这里省略函数实现代码*/

int get_front_next(c_SeQueue *q) {
    return (q->front + 1) % MAXSIZE;
}

void printerQueue()
{
    c_SeQueue* q = Init_SeQueue();
    int n, m, time = 0;
    int temp;
    datatype c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        In_SeQueue(q, temp);
    }
    while (!Empty_SeQueue(q)) {
        int max = get_front_next(q);
        for (int i = max + 1; i <= q->rear; i++) {
            if (q->data[max] < q->data[i]) {
                max = i;
            }
        }
        
        if (max != get_front_next(q)) {
            if (m == get_front_next(q)) {
                m = q->rear + 1;
            }
            Out_SeQueue(q, &c);
            In_SeQueue(q, c);
        } else {
            time++;
            if (m == get_front_next(q)) {
                printf("%5d", time);
                break;
            }
            Out_SeQueue(q, &c);
        }
    }


    // while (!Empty_SeQueue(q)) {
    //     //find max
    //     // max = q->front+1;
    //     // for (int i = q->front; i <= q->rear; i++) {
    //     //     if (q->data[max] < q->data[i]) {
    //     //         max = i;
    //     //     }
    //     // }

    //     // if (max != q->front + 1) {
    //     //     if (m == q->front + 1) {
    //     //         m = q->rear + 1;
    //     //     }
    //     //     Out_SeQueue(q, &c);
    //     //     In_SeQueue(q, c);
    //     // } else {
    //     //     time++;
    //     //     if (m == q->front + 1) {
    //     //         printf("%5d", time);
    //     //         break;
    //     //     }
    //     //     Out_SeQueue(q, &c);
    //     // }
    // }
}

int main()
{
    printerQueue();

    return 0;
}

c_SeQueue *Init_SeQueue() {
    c_SeQueue *q = (c_SeQueue *)malloc(sizeof(c_SeQueue));
    q->front = q->rear = MAXSIZE - 1;
    q->num = 0;
    return q;
}

int In_SeQueue(c_SeQueue *q, datatype x) {
    if (q->num == MAXSIZE) {
        printf("MAX\n");
        return -1;
    } else {
        q->rear = (q->rear + 1) % MAXSIZE;
        q->data[q->rear] = x;
        q->num++;
        return 1;
    }
}

int Out_SeQueue(c_SeQueue *q, datatype *x) {
    if (q->num == 0) {
        printf("NULL\n");
        return -1;
    } else {
        q->front = (q->front + 1) % MAXSIZE;
        *x = q->data[q->front];
        // q->front = (q->front + 1) % MAXSIZE;
        q->num--;
        return 1;
    }
}

int Empty_SeQueue(c_SeQueue *q) {
    if (q->num == 0) {
        return 1;
    } else {
        return 0;
    }
}