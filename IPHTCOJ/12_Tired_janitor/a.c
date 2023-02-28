#include <stdio.h>

int main(){
	int n, q;
  scanf("%d%d", &n, &q);
  long long a[n+1];
  for(int i = 1; i <= n; ++i){
    char str[20];
    scanf("%s", str);
    sscanf(str, "%lld", &a[i]);
    char tmp[6];
    scanf("%s", tmp);
  }
  
  long long b[n];
  b[1] = a[1];
  for(int i = 2; i <= n; ++i){
    b[i] = b[i-1]+a[i];
    //printf("b[%d] = %lld\n", i, b[i]);
  }
  
  for(int i = 0; i < q; ++i){
    int L, R;
    scanf("%d%d", &L, &R);
    printf("%lld\n", b[R]-b[L-1]);
  }
    
	return 0;
}