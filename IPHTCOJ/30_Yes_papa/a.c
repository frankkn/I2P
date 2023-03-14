#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool check(char a[], char b[], int n){
  if(n%2 == 1){
    return strcmp(a, b)== 0;
  }else{
    if(strcmp(a, b) == 0){
      return true;
    }else{
      int half = n/2;
      char a1[half+1], a2[half+1], b1[half+1], b2[half+1];
      strncpy(a1, a, half);
      a1[half] = '\0';
      strncpy(a2, a+half, half);
      a2[half] = '\0';
      strncpy(b1, b, half);
      b1[half] = '\0';
      strncpy(b2, b+half, half);
      b2[half] = '\0';
      return (check(a1, b1, half) && check(a2, b2, half)) ||
        (check(a1, b2, half) && check(a2, b1, half));
    }
  }
}

int main(){
  char a[1000], b[1000];
  scanf("%s%s", a, b);
  int n = strlen(a);
  if(check(a, b, n)){
    printf("%s", "YES\n");
  }else{
    printf("%s", "NO\n");
  }
  return 0;   
}