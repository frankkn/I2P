#include <stdio.h>

int main(){
 	int n;
  scanf("%d", &n);
	if(n%3 == 0){
    printf("%d", n/3*2+n%3+1);
  }else{
    printf("%d", n/3*2+n%3);
  }
  return 0;
}