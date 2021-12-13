#define MAXSIZE  1024 
#include <stdio.h>
#include <malloc.h>
struct Matrix
{
    int a;         /*矩阵的行数*/
    int b;         /*矩阵的列数*/
};
typedef  struct Matrix datatype;
typedef  struct
{
    datatype  data[MAXSIZE];
    int  top;
}SeqStack;

SeqStack *Init_SeqStack()/*这里省略函数实现代码*/
{
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}
int Empty_SeqStack(SeqStack *s)/*这里省略函数实现代码*/
{
    if (s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}
int Push_SeqStack (SeqStack *s, datatype  x)/*这里省略函数实现代码*/
{
    if (s->top == MAXSIZE - 1) {
        return 0;
    } else {
        s->top++;
        s->data[s->top] = x;
        return 1;
    }
}
int Pop_SeqStack(SeqStack *s, datatype *x)/*这里省略函数实现代码*/
{
    if (Empty_SeqStack(s)) {
        return 0;
    } else {
        *x = s->data[s->top];
        s->top--;
        return 1;
    }
}
int MatrixMultiply(struct Matrix m[], char st[], int len);

int main()
{
    struct Matrix m[26];
    char s[100],c;
    int n,i,k,length,ans;
    /*输入矩阵总数及各个矩阵的行数和列数 */
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
           scanf("%c",&c);
        k=c-'A';
        scanf("%d%d",&m[k].a,&m[k].b);
        getchar();
    }
    /*输入连乘矩阵表达式*/
    length=0;
    scanf("%c",&c);
    while(c!='@')
    {
        s[length]=c;
        length++;
        scanf("%c",&c);
    }

    ans = MatrixMultiply(m, s, length);
    if(ans==-1) printf("ERROR");
    else printf("%d",ans);

    return 0;
}

int my_isalpha(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    return 0;
}

int MatrixMultiply(struct Matrix m[], char st[], int len)
{
    SeqStack *s = Init_SeqStack();
    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (my_isalpha(st[i])) {
            Push_SeqStack(s, m[st[i] - 'A']);
        } else if (st[i] == ')') {
            datatype m2; 
            Pop_SeqStack(s, &m2);
            datatype m1;
            Pop_SeqStack(s, &m1);
            if (m1.b != m2.a) {
                return -1;
            }
            ans += m1.b * (m1.a * m2.b);
            m1.b = m2.b;
            Push_SeqStack(s, m1);
        }
    }
    return ans;
}