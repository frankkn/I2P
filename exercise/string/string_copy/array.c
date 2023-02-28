#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StrCopy(char* dst, char* str)
{
  int i = 0;
  while(str[i] != '\0')
  {
      dst[i] = str[i];
      i++;
  }
}

int main()
{
  char* src = "Frank";
  char* dst = (char*)malloc(strlen(src));
  StrCopy(dst, src);
  printf("%s", dst);
  return 0;
}