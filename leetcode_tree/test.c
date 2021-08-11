#include <stdio.h>
#include <stdbool.h>

bool func(){
    return false;
}

int main()
{
    if(func() == true)
        printf("hello\n");

    return 0;
}