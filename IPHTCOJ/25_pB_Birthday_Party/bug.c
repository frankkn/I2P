#include <stdio.h>
#include <stdbool.h>

int find_gcd(int a, int b){
	return !b ? a : find_gcd(b, a % b);
}

void distribute_balloon(int arr[], int n, int x){
	for(int i = 1; i <= n; ++i){
    if(find_gcd(i, x) != 1){
      arr[i]++;
    }
  }
}

void pony_balloon(int n, int x1, int x2, int x3){
	int arr[n+1];
    
  for(int i = 1; i <= n; ++i){ arr[i] = 0; }

  int co_prime1 = find_gcd(n, x1) == 1? 1:0;
  int co_prime2 = find_gcd(n, x2) == 1? 1:0;
  int co_prime3 = find_gcd(n, x3) == 1? 1:0;
  //printf("%d %d %d\n", co_prime1, co_prime2, co_prime3);
  int tmp = co_prime1 + co_prime2 + co_prime3;
  if(tmp == 3){
    printf("%d\n", n);
    return;
  }else{
    for(int i = 1; i <= n; ++i){
      arr[i] = tmp;
    }
  }
  if(co_prime1 != 1){	distribute_balloon(arr, n, x1); }
  if(co_prime2 != 1){	distribute_balloon(arr, n, x2); }
  if(co_prime3 != 1){	distribute_balloon(arr, n, x3); }
  int ans = 0;
  for(int i = 1; i <= n; ++i){
    if(arr[i] == 3){
      ans++;
    }
  }
	printf("%d\n", ans);
}

int main(){
	int T;
  scanf("%d", &T);
  while(T--){
    int n; scanf("%d", &n);
    int x1, x2, x3;
    scanf("%d%d%d", &x1, &x2, &x3);
    pony_balloon(n, x1, x2, x3);
  }
    
	return 0;
}