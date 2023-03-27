#include <stdio.h>

int main(){
    int r[26] = {0};
    int c[26] = {0};
    for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
        int num; scanf("%d", &num);
        r[num] = i;
        c[num] = j;
      }
    }
    int t; scanf("%d", &t);
    for(int cs = 1; cs <= t; ++cs){
      int row[5] = {0};
      int col[5] = {0};
		  int LURD = 0, RULD = 0;
        
    	int n; scanf("%d", &n);
      int arr[n]; // n:selected numbers
      for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
      }
      int q = 0;
      for(; q < n; ++q){
        if(++row[r[arr[q]]] == 5){
          printf("Case #%d: %d\n", cs, q+1);
          break;
        }
        if(++col[c[arr[q]]] == 5){
          printf("Case #%d: %d\n", cs, q+1);
          break;
        }
        if(r[arr[q]] == c[arr[q]]){
          if(++LURD == 5){
            printf("Case #%d: %d\n", cs, q+1);
            break;
          }
        }
        if(r[arr[q]] + c[arr[q]] == 4){
          if(++RULD == 5){
            printf("Case #%d: %d\n", cs, q+1);
            break;
          }
        }
      }
      if(q == n)	printf("Case #%d: Not yet \\(^o^)/\n", cs);
    }

}