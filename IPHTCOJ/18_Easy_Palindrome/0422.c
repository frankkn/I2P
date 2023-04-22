#include <stdio.h>

int main(){
	double n; scanf("%lf", &n);
  int int_part = (int)n % 1000;
  int fl_part = (n - int_part) * 1000;
  int a = 0;
  while(int_part){
    a *= 10;
    a += int_part % 10;
    int_part /= 10;
  }
  int b = 0;
  while(fl_part){
    b *= 10;
    b += fl_part % 10;
    fl_part /= 10;
  }
  double f = (double)b / 1000;
  double ans = n+a+f;
  printf("%.3lf", ans);
    
	return 0;
}