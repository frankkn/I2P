#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int a[1003][1003];
int MAX[1003], MIN[1003];

int main(){
	int n; scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    int _max = -(1 << 31);
    for(int j = 0; j < n; ++j){
      scanf("%d", &a[i][j]);
      _max = max(_max, a[i][j]);
    }
    MAX[i] = _max;
  }
  for(int j = 0; j < n; ++j){
    int _min = (1<<31)-1;
    for(int i = 0; i < n; ++i){
      _min = min(_min, a[i][j]);
    }
    MIN[j] = _min;
  }
  for(int i = 0; i < n; ++i){
    printf("%d", MAX[i]);
    if(i == n-1)	printf("\n");
    else	printf(" ");
  }
  for(int i = 0; i < n; ++i){
    printf("%d", MIN[i]);
    if(i == n-1)	printf("\n");
    else	printf(" ");
  }
}