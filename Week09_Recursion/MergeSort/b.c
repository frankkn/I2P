#include <stdio.h>

void merge(int *p, int *mid, int *end, int *result){
  int *q = mid+1;
  while(p <= mid && q <= end){
    if(*p <= *q){
      *result = *p;
      result++;
      p++;
    }else{
      *result = *q;
      result++;
      q++;
    }
  }
  
  while(p <= mid){
    *result = *p; 
    result++;
    p++;
  }
  
  while(q <= end){
    *result = *q;
    result++;
    q++;
  }

}

void merge_sort(int *start, int *end, int *result){
  if(start >= end){
    return;
  }else{
    merge_sort(start, start+(end-start)/2, result);
    merge_sort(start+(end-start)/2+1, end, result + (end-start)/2+1);
    merge(start, start+(end-start)/2, end, result);
    while(start <= end){
      *start = *result;
      start++;
      result++;
    }
    return;
  }
}

int main(){
  int a[9] = {4, 8, 9, 2, 1, 3, 5, 7, 6};
  int b[9] = {0}; 
  merge_sort(a, a+8, b);  
  for(int i = 0; i < 9; ++i){
    printf("%d, ", a[i]);
  }
  printf("\n");
  return 0;
}