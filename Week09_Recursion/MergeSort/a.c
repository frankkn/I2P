#include <stdio.h>
#define MAXN 100000

int data[MAXN], buffer[MAXN];

void merge(int starta, int lena, int startb, int lenb){
  int i = 0, j = 0, k = 0;
  while(i < lena && j < lenb){
    if(data[starta+i] < data[startb+j]){
      buffer[k++] = data[starta+i];
      i++;
    }else{
      buffer[k++] = data[startb+j];
      j++;
    }
  }
  while(i < lena){
    buffer[k++] = data[starta+i];
    i++;
  }
  while(j < lenb){
    buffer[k++] = data[startb+j];
    j++;
  }
}

void merge_sort(int L, int R){
  if(L >= R)  return;
  int M = (L+R)/2;
  merge_sort(L, M);
  merge_sort(M+1, R);
  merge(L, M-L+1, M+1, R-M);
  for(int i = 0; i < R-L+1; ++i){
    data[L+i] = buffer[i];
  }
}



int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &data[i]);
  }
  merge_sort(0, n-1);
  for(int i = 0; i < n; ++i){
    printf("%d ", data[i]);
  }
  printf("\n");
  return 0;
}