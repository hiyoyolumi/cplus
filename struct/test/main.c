#include "../HEAD.h"

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
    p->arrivd_time = data->arrivd_time;
    p->wait_time = data->wait_time;
    p->leave_time = data->leave_time;
    p->business_time = data->business_time;
    p->star_time = data->star_time;
    printf("%d\n", __LINE__);
    p->next = NULL;

    q->rear->next = p;
    printf("%d\n", __LINE__);
    q->rear = p;
    printf("%d\n", __LINE__);
}

int Out_Queue(Queue *q) {
    if (isEmpty(q)) {
        // TODO 感觉之后会在这里添东西
        printf("当前没有人排队\n");
        return 0;
    } else {
        //出队后 front 指向队头，出队的结点不会被释放
        q->front = q->front->next;
        if (q->front->next == NULL) {
            q->front = q->rear;
        }
        return 1;
    }
}

int get_rand_num()  {
    int a = rand()%480; //朝九晚五，工作八个小时，480分钟
    return a;
}

Time get_rand_time() {
    int time_min = get_rand_num();
    //TODO 把分钟(time)转化成时间
    Time time_h;
    time_h.min_h = 9 + (time_min / 60);
    time_h.min_min = time_min % 60;
    return time_h;
}

int get_serial_num(Queue *q) {
    //返回当前最大编号的下一位
    return q->rear->serial_num + 1;
}

Time turn_to_time(int min) {
    Time time_h;
    time_h.min_h = 9 + (min / 60);  //早上九点上班
    time_h.min_min = min % 60;
    return time_h;
}

/**
 * @brief Get the leave time object
 *        实现应该用 star_time + 10min
 * 
 * @param arrived_time 
 * @return Time 
 */
void get_leave_time(Time_data *node) {
    //先判断有没有空闲窗口
    int win_serial;
    win_serial = get_free_window();
    // printf("窗口编号：%d\n", win_serial);
    if (win_serial == -1) {
        //没有空闲窗口

        //找到最早结束的窗口
        int min_win_serial = find_fast_window();
        
        //最早窗口的离开时间就是排队第一人的开始时间(star_time)
        //但是由于程序最初的设计问题，在第一轮之后窗口的status无法回到0
        //所以，需要对最早窗口的离开时间进行判断
        Time temp_leave_time = windows[min_win_serial].cur_leave_time;
        if (compare_time(temp_leave_time, node->arrivd_time) == 1) {
            node->star_time = node->arrivd_time;
        } else {
            node->star_time = windows[min_win_serial].cur_leave_time;
        }
        node->window_serial = min_win_serial;
        node->leave_time = star_to_leave(node);
    } else {
        //有空闲窗口
        
        //将该窗口设置为占用
        windows[win_serial].status = 1;
        //将客户编号赋值给窗口
        windows[win_serial].cur_custom_serial = node->serial_num;
        node->window_serial = win_serial;
        node->star_time = node->arrivd_time;
        node->leave_time = star_to_leave(node);
    }
}

int find_fast_window() {
    Time min = windows[0].cur_leave_time;
    int min_win_serial = 0;
    for (int i = 1; i < WINDOW_NUMS; i++) {
        if (compare_time(min, windows[i].cur_leave_time) == 0) {
            min_win_serial = i;
            min = windows[i].cur_leave_time;
        }
    }
    return min_win_serial;
}

Time star_to_leave(Time_data *node) {
    Time leave_time;
    
    //15:40 + 40 = 16:20
    if (node->star_time.min_min + node->business_time >= 60) {
        node->leave_time.min_h = node->star_time.min_h + 1;
        node->leave_time.min_min = node->star_time.min_min 
                                    - 60 + node->business_time;
    } else {
        node->leave_time.min_h = node->star_time.min_h;
        node->leave_time.min_min = node->star_time.min_min + node->business_time;
    }
    
}

int get_free_window() {
    for (int i = 0; i < WINDOW_NUMS; i++) {
        if (windows[i].status == 0) {
            return i;
        }
    }
    return -1;
}

void print_node(Time_data *t) {
    printf("-------------------------");
    printf("客户编号：%d\n", t->serial_num);
    printf("办理业务窗口：%d\n", t->window_serial);
    printf("到达时间：%d\n", t->arrivd_time);
    printf("开始时间：%d\n", t->star_time);
    printf("离开时间：%d\n", t->leave_time);
    printf("办理业务时间：%d\n", t->business_time);
    printf("-------------------------");
}
void print_queue(Queue *q) {
    while (!isEmpty(q)) {
        print_node(q->front);
        Out_Queue(q);
    }
}

int main() {
    srand((unsigned)time(NULL));
    Queue *q = initQueue();
    init_custom(q);
    print_queue(q);
    return 0;
}