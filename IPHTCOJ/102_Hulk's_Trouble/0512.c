#include <stdio.h>
#include <stdlib.h> // for qsort()
int a[(int)1e5+3];

int LB(int L, int R, int target){
	while(L < R){
    int M = (L+R)/2;
    if(a[M] >= target){
      R = M;
    }else{
      L = M+1;
    }
  }
	return L;
}

int UB(int L, int R, int target){
	while(L < R){
    int M = (L+R)/2;
    if(a[M] > target){
      R = M;
    }else{
      L = M+1;
    }
  }
	return L;
}

int cmp(const void* a, const void* b){
	int *aa = (int*) a;
  int *bb = (int*) b;
	//return *aa-*bb;
  // A negative value if a should come before b
  // A positive value if a should come after b  
  // Zero if a and b are considered equal
  if(*aa < *bb){
    return -1;
  }else if(*aa == *bb){
    return 0;
  }else{
    return 1;
  }
}

int main(){
	int n; scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
  qsort(a, n, sizeof(a[0]), cmp);
  int q; scanf("%d", &q);
  while(q--){
    int num; scanf("%d", &num);
    int lower_bound = LB(0, n, num);
    int upper_bound = UB(0, n, num);
    printf("%d\n", upper_bound-lower_bound);
  }
	return 0;
}