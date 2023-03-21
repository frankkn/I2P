#include <stdio.h>

int main(){
  int n; scanf("%d", &n);
  char s[n+1]; scanf("%s", s);
  int L = 0, R = 0;
  for(int i = 0; i < n; ++i){
    if(s[i] == 'L') L++;
    else  R++;
  }
  printf("%d\n", L+R+1);

  return 0;
}