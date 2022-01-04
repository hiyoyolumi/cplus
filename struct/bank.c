#include "HEAD.h"
#include "linklist.h"

extern Window_status windows[WINDOW_NUMS];

//初始化随机顾客
void init_custom(Queue *q) {
    Lnode *Lhead;
    Lhead = Create();
    //此时 Lhead 中存放随机生成的顾客
    //对链表进行排序
    sortList(Lhead);
    //将顾客到达时间存入 队列 中
    Lnode *t = Lhead->next;
    while (t) {
        Time_data *temp;
        temp = (Time_data *)malloc(sizeof(Time_data));
        Time duff;
        duff = turn_to_time(t->data);
        //给队列结点的 vip_status 赋值
        temp->vip_status = if_is_vip();
        //给队列结点的 arrived_time wait_time leave_time 赋值
        temp->arrivd_time = duff;
        temp->business_time = (rand() % 30) + 1;    //最少 1 min

        //给结点的客户编号赋值
        temp->serial_num = get_serial_num(q);
        // leave_time 基本实现了，但是感觉会出 BUG
        // 这里竟然没出BUG，反而是下面的入队代码出BUG了
        // 入队代码修好了，因为我没有给传入的指针分配空间
        // 现在还是 leave_time 有BUG
        // 将 leave_time 存入 temp 中
        // 现在没啥问题了
        get_leave_time(q, temp);
        // printf("window_serial = %d\n", temp->window_serial);
        //入队
        Enqueue(q, temp);
        t = t->next;
        free(temp);
    }

    link_destory(Lhead);


    //这个思路不行，换一个思路
    // //对VIP用户进行重排
    // sortQueue_vip(q);
    
    // //这里修改之后为什么还是不对呢？
    // init_windows();
    // Time_data *temp = q->head->next;
    // while (temp) {
    //     get_leave_time(q, temp);
    //     temp = temp->next;
    // }

    //导入队列完毕之后，将链表销毁，节省内存
}

void sortQueue_vip(Queue *q) {
    Time_data *t = q->head->next;
    Time_data *q_t = q->head;
    while (t) {
        if (t->vip_status) {
            Time_data *temp = q->head->next;
            Time_data *q_temp = q->head;
            while (temp != t) {
                if (is_the_time(temp, t->arrivd_time) == 2) {
                    Time_data *temp1 = t->next;
                    Time_data *temp2 = temp->next;
                    q_temp->next = t;
                    q_temp->next->next = temp2;
                    q_t->next = temp;
                    q_t->next->next = temp1;
                    break;
                }
                temp = temp->next;
                q_temp = q_temp->next;
            }
            get_leave_time(q, t);
            get_leave_time(q, temp);
            t = temp;
            t = t->next;
            continue;
        }
        t = t->next;
        q_t = q_t->next;
    }
}

int if_is_vip() {
    // 10 个人里有一个VIP
    int a = rand() % 10;
    if (a == 1) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void init_windows() {
    for (int i = 0; i < WINDOW_NUMS; i++) {
        windows[i].cur_custom_serial = 0;
        windows[i].cur_leave_time.min_h = 0;
        windows[i].cur_leave_time.min_min = 0;
        windows[i].status = 0;
    }
}

//走进银行
int Step_in(Queue *q) {
    //打印银行欢迎界面
    welcome();

    //初始化队列
    // Queue *q = initQueue();
    // if (q == NULL) {
    //     printf("队列初始化失败\n");
    //     return;
    // }

    while (1) {
        //打印菜单界面
        menu();

        int temp;
        scanf("%d", &temp);
        switch (temp) {
            case 1:
                //查询业务办理情况
                inquiry_business_handle(q);
                break;
            case 2:
                //系统查询
                print_queue(q);
                break;

            case 3:
                //进入下一天
                return 1;

            case 4:
                //退出系统
                return 0;

            default:
                printf("---请输入指定序号\n");
                break;
        }
    }
}

void inquiry_business_handle(Queue *q) {
    printf("---输入查询时间点:");
    Time temp_time;
    scanf("%d:%d", &temp_time.min_h, &temp_time.min_min);

    /**
     * @brief 根据输入的时间 输出 当前的排队状况
     *
     * 关键点！！！
     */
    get_queue_situation(q, temp_time);
}

void get_queue_situation(Queue *q, Time input_time) {
    //遍历队列，找到输入时间之前的时间结点
    Time_data *t = q->head->next;
    int x = 0;
    while (t) {
        int flag = is_the_time(t, input_time);
        if (flag == 0) {
            
        } else if (flag == 1) {
            x = 1;
            print_deal_node(t);
        } else if (flag == 2) {
            x = 1;
            print_wait_node(t);
        } else if (flag == 3) {
            break;
        }
        t = t->next;
    }
    if (!x) {
        printf("\n---当前银行没有客户\n");
    }
}

int is_the_time(Time_data *t, Time input_time) {
    if (  //表示 t 结点的客户在输入时间点正在排队
        (compare_time(t->arrivd_time, input_time) == 1) &&
        (compare_time(t->star_time, input_time) == 0)) {
        
        return 2;

    } else if ( //表示 t 结点的客户在输入时间点正在办理业务
        (compare_time(t->arrivd_time, input_time) == 1) && 
        (compare_time(t->leave_time, input_time) == 0)) {
        
        return 1;

    } else if ((compare_time(t->arrivd_time, input_time) == 0)) {
        //表示当前结点的到达时间已经比输入时间晚了
        return 3;
    } else {
        return 0;
    }
}

int compare_time(Time ti1, Time ti2) {
    if (ti1.min_h < ti2.min_h) {
        return 1;
    } else if (ti1.min_h > ti2.min_h) {
        return 0;
    } else {
        if (ti1.min_min < ti2.min_min) {
            return 1;
        } else if (ti1.min_min > ti2.min_min) {
            return 0;
        } else {
            return 2;
        }
    }
}

void print_wait_node(Time_data *t) {
    printf("-------------------------");
    printf("客户编号：%d\n", t->serial_num);
    printf("到达时间：%d:%d\n", t->arrivd_time.min_h, t->arrivd_time.min_min);
    printf("正在排队......\n");
    printf("-------------------------\n");
}

void print_deal_node(Time_data *t) {
    printf("-------------------------");
    printf("客户编号：%d\n", t->serial_num);
    printf("到达时间：%d:%d\n", t->arrivd_time.min_h, t->arrivd_time.min_min);
    printf("办理业务窗口：%d\n", t->window_serial);
    printf("开始时间：%d:%d\n", t->star_time.min_h, t->star_time.min_min);
    printf("正在办理业务......\n");
    printf("-------------------------\n");
}

void print_node(Time_data *t) {
    printf("-------------------------");
    printf("客户编号：%d\n", t->serial_num);
    if (t->vip_status == 1) {
        printf("\e[31;43m 客户身份：VIP \e[0m\n");
    } else {
        printf("客户身份：普通\n");
    }
    if (t->window_serial == 100) {
        printf("办理业务窗口：VIP窗口\n");
    } else {
        printf("办理业务窗口：%d\n", t->window_serial);
    }
    printf("到达时间：%d:%d\n", t->arrivd_time.min_h, t->arrivd_time.min_min);
    printf("开始时间：%d:%d\n", t->star_time.min_h, t->star_time.min_min);
    printf("离开时间：%d:%d\n", t->leave_time.min_h, t->leave_time.min_min);
    printf("办理业务时间：%d (min)\n", t->business_time);
    printf("-------------------------\n");
}
void print_queue(Queue *q) {
    while (!isEmpty(q)) {
        print_node(q->front->next);
        Out_Queue(q);
    }
}