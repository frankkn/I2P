#include <stdio.h>
int a[20];
int cnt;

void dfs(int idx, int sum, int n, int k){
    if(sum > k) return;
	if(sum == k){
    	cnt++;
      return;
  }else{
    for(int i = idx; i < n; ++i){
    sum += a[i];
      dfs(i + 1, sum, n, k);
      sum -= a[i];
    }
  }
}


int main(){
	int n, k;
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; ++i)scanf("%d", &a[i]);
  dfs(0, 0, n, k);
  printf("%d\n", cnt);
	return 0;
}