#include <stdio.h>
#define ll long long

ll target = 0;
int cnt = 0;

void dfs(int a[], int n, int idx, ll sum){
  if(sum > target) 	return;
  if(sum == target){
    cnt++;
    return;
  }
  
  for(int i = idx; i < n; ++i){
    sum += a[i];
    dfs(a, n, i+1, sum);
    sum -= a[i];
  }
}

int main(){
	int n; 
  scanf("%d%lld", &n, &target);
  int a[n];
  for(int i = 0; i < n; ++i)	scanf("%d", &a[i]);
	dfs(a, n, 0, 0);
  printf("%d\n", cnt);
  return 0;
}