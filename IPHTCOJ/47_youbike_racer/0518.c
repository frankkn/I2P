#include <stdio.h>
int a[(int)1e5+3];

int main(){
	int n, k; scanf("%d%d", &n, &k);
  for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
  int now_pos = 0;
  int cnt = 0;
  int gas_remain = k;
  for(int i = 0; i < n; ++i){
    // can arrive
    if(gas_remain + now_pos >= a[i]){
      gas_remain -= (a[i]-now_pos);
    }else{
      if(k + now_pos >= a[i]){
        gas_remain = k;
        gas_remain -= (a[i]-now_pos);
        cnt++;
      }else{
        printf("The Legend Falls.\n");
        return 0;
      }
    }
    now_pos = a[i];
  }
  printf("%d\n", cnt);
	return 0;
}