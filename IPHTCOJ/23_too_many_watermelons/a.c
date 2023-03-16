#include <stdio.h>

int main(){
	int n;
  scanf("%d", &n);
  int a[(int)2e5], b[(int)2e5];
  for(int i = 0; i < n; ++i)  scanf("%d", &a[i]);
  for(int i = 0; i < n; ++i)  scanf("%d", &b[i]);
  
  int p = 0;
  int used[(int)2e5] = {0}; // all init to 0, can only be initialized to 0
    
  for(int i = 0; i < n; ++i){
    int cur_wm = b[i];
    if(used[cur_wm] == 1){
      printf("%d ", 0);
      continue;
    }
    int cnt = 0;
    while(a[p] != cur_wm){
      used[a[p]] = 1;
      cnt++;
      p++;
    }
    cnt++;p++;
    used[cur_wm] = 1;
    printf("%d ", cnt);
  }
  printf("\n");
	return 0;
}