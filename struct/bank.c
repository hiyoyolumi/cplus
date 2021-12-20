#include "HEAD.h"
#include "linklist.h"

//用于存储(排序后的)用户信息
//用于存入队列中
//可改进为链表存储
//排序方法可借鉴 leetcode 中 148 题
Time_data customs[100];

//初始化随机顾客
//在这个函数中
// void init_custom() {
//     int temp[100];
//
//     printf("请输入顾客人数:");
//     int n;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) {
//         temp[i] = get_rand_num();
//         // customs[i].arrivd_time = get_rand_time();
//     }
//     //对随机生成的时间进行排序
//     qsort(temp, n, sizeof(int), cmpfunc);
//  
//     //将 temp 中的 min 转换到 customs.arrived (Time)
//     for (int i = 0; i < n; i++) {
//         customs[i].arrivd_time = turn_to_time(temp[i]);
//     }
// }

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
        Time duff;
        duff = turn_to_time(t->data);
        //给队列结点的 arrived_time wait_time leave_time 赋值
        temp->arrivd_time = duff;
        temp->wait_time = 10;
        temp->leave_time = get_leave_time(temp->arrivd_time);
        //入队
        Enqueue(q, temp);

        t = t->next;
    }
    //导入队列完毕之后，将链表销毁，节省内存
    link_destory(Lhead);
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
        switch (temp)
        {
        case 1:
            //查询业务办理
            inquiry_business_handle(q);
            break;
        case 2:
            //系统查询

            break;

        case 3:
            //进入下一天
            return 1;

        case 4:
            //退出系统
            return 0;

        default:
            printf("请输入指定序号\n");
            break;
        }
    }
}

void inquiry_business_handle(Queue *q) {
    printf("输入查询时间点:");
    Time temp_time;
    scanf("%d:%d", &temp_time.min_h, &temp_time.min_min);
    
}
