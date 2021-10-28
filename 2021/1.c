#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "I love Linux\0\0\0";
    int a = sizeof(s);
    int b = strlen(s);

    printf("%d %d\n", a, b);

    return 0;
}