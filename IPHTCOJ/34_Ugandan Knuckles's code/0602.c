#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[1000][1001];

int cmp(const void *a, const void *b){
  return strlen((char*)a) - strlen((char*)b);
}

int main(){
  int n; scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%s", str[i]);
  }
  qsort(str, n, sizeof(str[0]), cmp);
  for(int i = 0; i < n-1; ++i){
    if(!strstr(str[i+1], str[i])){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  for(int i = 0; i < n; ++i){
    printf("%s\n", str[i]);
  }

  return 0;
}