#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    int a[(int)2e5+1], b[(int)2e5+1];
    for(int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i)	scanf("%d", &b[i]);
    int used[(int)2e5+1] = {0};
    int j = 1;
    for(int i = 1; i <= n; ++i){
    	int cnt = 0;
        if(used[b[i]] == 0){ // b[i] not yet eatten
        	used[b[i]] = 1;
            while(a[j] != b[i]){
                used[a[j]] = 1;
            	j++;
                cnt++;
            }
            cnt++;
            j++;
            printf("%d", cnt);
        }else{
        	printf("0");
        }
       	printf("%c", i==n?'\n':' ');        
    }
  	return 0;
}
    