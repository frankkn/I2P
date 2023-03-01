#include <stdio.h>

int main(){
	int n;
  scanf("%d", &n);
  int a[n], b[n];
  for(int i = 0; i < n; ++i){
    int cur_a;
    scanf("%d", &cur_a);
    a[i] = cur_a;
  }
  for(int i = 0; i < n; ++i){
    int cur_b;
    scanf("%d", &cur_b);
    b[i] = cur_b;
  }
  
  int p = 0;
  int used[n+1];
  for(int i = 0; i <= n; ++i){
    used[i] = 0;
  }
    
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