#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StrCopy(char* dst, char* str)
{
  while(*str != '\0')
  {
    *dst++ = *str++;
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