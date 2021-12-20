#include "HEAD.h"

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void welcome() {
    //变色功能在 Linux 系统下适用，在 Windows 系统下不可用
    printf("\e[37;40m ********************************** \e[0m\n");
    printf("\e[37;44m *         欢迎登录银行系统          * \e[0m\n");
    printf("\e[37;44m * Welcome to the banking system  * \e[0m\n");
    printf("\e[37;44m *                                * \e[0m\n");
    printf("\e[31;43m *          ****  ****            * \e[0m\n");
    printf("\e[31;43m *         ************           * \e[0m\n");
    printf("\e[31;43m *        **************          * \e[0m\n");
    printf("\e[31;43m *          **********            * \e[0m\n");
    printf("\e[31;43m *            ******              * \e[0m\n");
    printf("\e[31;43m *              **                * \e[0m\n");
    printf("\e[37;40m ********************************** \e[0m\n");
}

void menu() {
    printf("1. 查询业务办理\n");
    printf("2. 系统查询\n");
    printf("3. 退出\n");
}

void good_bye() {
    printf("\e[37;44m Good Bye \e[0m\n");
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
    time_h.min_h = min / 60;
    time_h.min_min = min % 60;
    return time_h;
}

Time get_leave_time(Time arrived_time) {
    Time leave_time;
    if (arrived_time.min_min + 10 >= 60) {
        leave_time.min_h = arrived_time.min_h + 1;
        leave_time.min_min = arrived_time.min_min - 50;
    } else {
        leave_time.min_h = arrived_time.min_h;
        leave_time.min_min = arrived_time.min_min + 10;
    }
    return leave_time;
}