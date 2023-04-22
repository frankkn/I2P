#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int find_occ(char A[], char B[]){
	int n1 = strlen(A), n2 = strlen(B);
  int cnt = 0;
  for(int i = 0; i <= n2 - n1; ++i){
    if(strncmp(A, B+i, n1) == 0){
      cnt++;
    }
  }
  return cnt;
}

char A[5], B[10];
int main(){
	scanf("%s", A);
  int n; scanf("%d", &n);
  int _max = 0;
  for(int i = 0; i < n; ++i){
    char B[10]; scanf("%s", B);
    _max = max(_max, find_occ(A, B));
  }
	printf("%d\n", _max);
	return 0;
}