#include <stdio.h>

int main(){
	int arr[300001];
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i){
    arr[100000+i] = i;
  }
  int idx = 0;
  while(m--){
    int e; scanf("%d", &e);
    arr[100000-idx] = e;
    idx++;
  }
  int used[200001];
  for(int i = 100000-idx+1; i <= 100000+n; i++){
    if(!used[arr[i]]){
      printf("%d\n", arr[i]);
      used[arr[i]] = 1;
    }
  }
	return 0;
}