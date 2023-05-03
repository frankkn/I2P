#include <stdio.h>

int main(){
	int n; scanf("%d",&n);
    int a[(int)2e5+1], b[(int)2e5+1], used[(int)2e5+1] = {0};
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    int cur = 1;
    for(int i = 1; i <= n; ++i){
    	if(used[b[i]] == 0){
        int cnt = 0;
        while( cur <= n ){
          if(a[cur] != b[i]){
            u sed[a[cur]] = 1;
            cur++;
            cnt++;
          }else{
            used[a[cur]] = 1;
            cur++;
            cnt++;
            break;
          }
        }
        printf("%d", cnt);
      }else{
        printf("0");
      }
    if(i != n)	printf(" ");
    }
	return 0;
}