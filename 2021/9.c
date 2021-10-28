#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *convert(const char *s) {
    char *temp;
    temp = (char *)malloc(sizeof(char) * sizeof(s));
    memset(temp, 0, sizeof(temp));
    strcpy(temp, s);
    for (int i = 0; i < strlen(temp); i++) {
        if (islower(temp[i])) {
            temp[i] = toupper(temp[i]);
        } else if (isupper(temp[i])) {
            temp[i] = tolower(temp[i]);
        }
    }

    return temp;
}

int main(void) {
  char *str = "XiyouLinux Group 2022";
  char *t = convert(str);
  puts(t);
}