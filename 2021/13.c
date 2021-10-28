#include <stdio.h>

int main(void) {
  int data[] = {0X636c6557, 0X20656d6f, 0X78206f74, 0X756f7969, 0X6e694c20,
                0X67207875, 0X70756f72, 0X32303220, 0X0a31};
  puts((const char*)data);
}