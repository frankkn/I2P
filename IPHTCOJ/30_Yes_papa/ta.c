#include <stdio.h>
#include <string.h>

char a[1000], b[1000];

int dir_comp(int al, int ar, int bl, int br){
  for(int i = al, j = bl ; i <= ar, b <= br; ++i, ++j){
    if(a[i] != b[i])  return 0; 
  }
  return 1;
}

int compare(int al, int ar, int bl, int br){
  //if((ar - al + 1) % 2) return dir_comp(al, ar, bl, br);
  if((ar - al + 1) % 2) return !strncmp(a+al, b+bl, ar-al+1); // a+al !! not al
  int am = al + (ar-al) / 2;
  int bm = bl + (br-bl) / 2;
  // case 1
  int s1 = compare(al, am, bl, bm); // a1 vs b1
  int s2 = compare(am+1, ar, bm+1, br); // a2 vs b2
  // case 2
  int s3 = compare(al, am, bm+1, br); // a1 vs b2
  int s4 = compare(am+1, ar, bl, bm); // a2 vs b1
  return (s1 && s2) || (s3 && s4);
}

int main(){
  scanf("%s %s", a, b);
  if(compare(0, strlen(a)-1, 0, strlen(b)-1)){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}