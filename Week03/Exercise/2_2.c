#include <stdio.h>
#include <string.h>
int main(void)
{
  int i, k;
  char num[100];
  int len;
  int x;

  scanf("%s", num);

  printf("The number %d can be expressed as\n", i);
  k = 1;

  len = strlen(num);
  i = 0;
  x = 0;

  while (i < len) {
    printf("%c*%d + ", num[len-i-1], k);
    k = k*10;

    x = x*10 + (num[i] - '0');
    i++;
  }
  
  printf("\b\b\b.  \n");
  printf("x = %d\n", x);

  return 0;
}