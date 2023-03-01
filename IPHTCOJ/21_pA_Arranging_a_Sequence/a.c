#include <stdio.h>

int main(){
	int n, m;
  scanf("%d%d", &n, &m);
  int arr[300001] = {};
  for(int i = 1; i <= n; ++i){
    arr[100000+i] = i;
  }
  int used[n+1];
  for(int i = 0; i <= n; ++i){
    used[i+1] = 0;
  }
  int p = 100000;
  for(int i = 0; i < m; ++i){
    int cur_move_num; 
    scanf("%d", &cur_move_num);
    arr[p--] = cur_move_num;
  }
  for(int i = 0; i < 300001; ++i){
    if(arr[i] != 0 && used[arr[i]]==0){
      used[arr[i]] = 1;
      printf("%d\n", arr[i]);
    }
  }
	return 0;
}