#include <stdio.h>

int main(){
	int b, c, d;
  scanf("%d%d%d", &b, &c, &d);
  int a, e;
  if((c-b) == (d-c)){ // 等差
    a = 2*b - c;
    e = 2*d - c;
  }else{
    a = b * b / c ;
    e = d * d / c ;
  }
  printf("%d %d\n", a, e);
    
	return 0;
}