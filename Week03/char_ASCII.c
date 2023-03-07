#include <stdio.h>
int main(void)
{
  char i = 48;
  while (i < 57) {
    printf("%3d:  %c\n", i, i);
    i++;
  }
  printf("-------------\n");
  int j = 'A'; // 65
  while (j <= 'Z') {
    printf("  %c: %3d\n", j, j);
    j++;
  }

  return 0;
}