#include <stdio.h>

int arr[(int)1e6+1] = {0};
int prefix[(int)1e6+1] = {0};

int count(int i){
  int cnt = 0;
  while(i){
    if(i%10==1) cnt++;
    i /= 10;
  }
  return cnt;
}

int main(){
  int t; 
  scanf("%d", &t);

  prefix[0] = 0;
  for(int i = 1; i <= 1e6; ++i){
    arr[i] = count(i);
    prefix[i] = prefix[i-1] + arr[i];
  }

  while(t--){
    int L, R;
    scanf("%d%d", &L, &R);
    printf("%d\n", prefix[R]-prefix[L-1]);
  }

  return 0;
}