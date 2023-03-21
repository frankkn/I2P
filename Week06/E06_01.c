/*
宣告 double power(double n, int p); ，然後使用下面的方式來做遞迴:
(0) 先檢查 p 是否等於 0，是的話就傳回答案 1; 若 p 不等於 0 則先算出 ans = power(n, p/2);
(1) 如果 p 是偶數，則 return ans*ans;
(2) 如果 p 是奇數，則 return n*ans*ans;
這裡有使用到整數除法無條件捨去的特性。
*/
#include <stdio.h>
double power(double n, int p);

int main(void)
{
  double x;
  int t;
  scanf("%lf", &x);
  scanf("%d", &t);
  printf("%f\n", power(x, t));

  return 0;
}

double power(double n, int p)
{
  double ans;
  if (p == 0) {
      return 1.0;
  }
  ans = power(n, p/2);
  if (p%2 == 0) {
      return ans*ans;
  } else {
      return n*ans*ans;
  }
}
