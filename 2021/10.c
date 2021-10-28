#include <stdio.h>

#define Swap1(a, b, t)                                                         \
  do {                                                                         \
    t = a;                                                                     \
    a = b;                                                                     \
    b = t;                                                                     \
  } while (0)

#define Swap2(a, b)                                                            \
  do {                                                                         \
    int t = a;                                                                 \
    a = b;                                                                     \
    b = t;                                                                     \
  } while (0)
void Swap3(int a, int b) {
  int t = a;
  a = b;
  b = t;
}

int main()
{
    int a = 1, b = 2;
    int t = 5;
    Swap1(a,b,t);
    printf("a = %d b = %d\n", a, b);
    Swap2(a, b);
    printf("a = %d b = %d\n", a, b);
    Swap3(a, b);
    printf("a = %d b = %d\n", a, b);
}