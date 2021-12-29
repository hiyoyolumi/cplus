#include "HEAD.h"

extern Window_status windows[WINDOW_NUMS];
extern Window_status VIP_window;

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void welcome() {
    //变色功能在 Linux 系统下适用，在 Windows 系统下不可用
    printf("\e[37;40m ********************************** \e[0m\n");
    printf("\e[37;44m *         欢迎登录银行系统       * \e[0m\n");
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
    printf("\n1. 查询业务办理情况\n");
    printf("2. 系统查询\n");
    printf("3. 开始下一天\n");
    printf("4. 退出\n");
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
void get_leave_time(Queue *q, Time_data *node) {
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
        //在加入VIP功能之后，这个地方会引起BUG
        Time temp_leave_time = windows[min_win_serial].cur_leave_time;
        //如果是VIP的话，就要判断VIP窗口快还是普通窗口快
        Time temp_vip_leave_time;
        if (node->vip_status == 1) {
            if (VIP_window.status == 1) {   //VIP通道有人去过的话
                temp_vip_leave_time = VIP_window.cur_leave_time;
                //比较VIP通道和普通通道哪个更快
                if (compare_time(temp_vip_leave_time, temp_leave_time) == 1) {
                    //走VIP通道
                    if (compare_time(temp_vip_leave_time, node->arrivd_time) == 1) {
                        //说明当前没有人排队
                        node->star_time = node->arrivd_time;
                    } else {
                        node->star_time = VIP_window.cur_leave_time;
                    }
                    node->window_serial = 100;
                    star_to_leave(node);
                    VIP_window.cur_leave_time = node->leave_time;
                } else {
                    //排普通通道更快
                    if (compare_time(temp_leave_time, node->arrivd_time) == 1) {
                        node->star_time = node->arrivd_time;
                    } else {
                        node->star_time = windows[min_win_serial].cur_leave_time;
                    }
                    node->window_serial = min_win_serial;
                    star_to_leave(node);
                    windows[min_win_serial].cur_leave_time = node->leave_time;
                }
            } else {
                VIP_window.status = 1;
                VIP_window.cur_custom_serial = node->serial_num;
                node->window_serial = 100;
                node->star_time = node->arrivd_time;
                star_to_leave(node);
                VIP_window.cur_leave_time = node->leave_time;
            }
            return;
        }

        if (compare_time(temp_leave_time, node->arrivd_time) == 1) {
            node->star_time = node->arrivd_time;
        } else {
            node->star_time = windows[min_win_serial].cur_leave_time;
        }
        node->window_serial = min_win_serial;
        star_to_leave(node);
        windows[min_win_serial].cur_leave_time = node->leave_time;
    } else {
        //有空闲窗口
        
        //将该窗口设置为占用
        windows[win_serial].status = 1;
        //将客户编号赋值给窗口
        windows[win_serial].cur_custom_serial = node->serial_num;
        node->window_serial = win_serial;
        node->star_time = node->arrivd_time;
        star_to_leave(node);
        windows[win_serial].cur_leave_time = node->leave_time;
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

void star_to_leave(Time_data *node) {
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