/*
用 recursive 方式，產生下面的輸出
Input: 10 
Output: ((((1+2)*3+4)*5+6)*7+8)*9+10=4555 
Input: 11 
Output: (((((1+2)*3+4)*5+6)*7+8)*9+10)*11=50105
*/

#include <stdio.h>
int show_parenthesis(int n);

int main(void)
{
  int n;
  int ans;
  scanf("%d", &n);
  ans = show_parenthesis(n);
  printf("=%d\n", ans);
  return 0;
}

int show_parenthesis(int n)
{
  int ans = 1;
  if (n>1) {
    if (n%2) {
      printf("(");
    }
    ans = show_parenthesis(n-1);
    if (n%2) {
      printf(")*%d",n);  
      ans = ans * n;      
    } else {
      printf("+%d", n);
      ans = ans + n;
    }
  } else {
      printf("1");
  }
  return ans;
}
