/* 
使用者輸入一串字元(讀到 '\n' 就結束)
把這串字元裡全部的英文字母都轉成小寫再輸出 
*/
#include <stdio.h>
#include <ctype.h>
int main(void)
{
  freopen("testcase.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  char ch;

  while ( (ch=getchar()) != EOF ) {         
    putchar(tolower(ch));
  }

  putchar('\n');   

  return 0;
}