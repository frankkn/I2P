#include <stdio.h>

int main(){
	int n,q; scanf("%d%d", &n, &q);
  int a[(int)1e6+3];
  long long pr[(int)1e6+3]; 
  pr[0] = 0;
  for(int i = 1; i <= n; ++i) {	
    scanf("%d", &a[i]); 
    if(a[i] > 0)	pr[i] = pr[i-1]+a[i];
    else	pr[i] = pr[i-1];
  }
  while(q--){
    int L,R,M; scanf("%d %d %d", &L,&R,&M);
    printf("%lld\n", pr[L+M-1]-pr[L-1]);
  }
	return 0;
}