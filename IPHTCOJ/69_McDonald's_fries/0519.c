#include <stdio.h>
#define ll long long

int lower_bound(ll a[], int L, int R, ll target){
	while(L < R){
    int M = (L+R)/2;
    if(a[M] >= target) R = M;
    else L = M+1;
  }
	return R;
}

int main(){
	int n, k, q; scanf("%d%d%d", &n, &k, &q);
  ll a[(int)1e6+3];
  for(int i = 0; i < n; ++i) scanf("%lld", &a[(i + (n-k)) % n]);
  while(q--){
    ll target; scanf("%lld", &target);
    int x = lower_bound(a, 0, n-k, target);
    int y = lower_bound(a, n-k, n, target);
    // printf("x:%d y:%d\n", x, y);
    if(x == (n-k)){
      printf("gan ni nya sai bau\n");
    }else{
      if(y == n){	printf("%d\n", x+1); }
      else{
        // 都找到，基本上要印右邊的，但是有一種情況就是左邊找到的==右邊找到的，這種情況才印左邊。
        if(a[x] == a[y]){
          printf("%d\n", x+1);
        }else{
          printf("%d\n", y+1);
        }
        /*這樣寫也可以
        if(a[x] <= a[y]){
          printf("%d\n", x+1);
        }else{
          printf("%d\n", y+1);
        }*/
      }
    }
  }
	return 0;
}