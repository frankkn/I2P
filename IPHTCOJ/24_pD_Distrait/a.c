#include <stdio.h>
#include <string.h>

typedef struct Pair{
	int first;
  int second;
}Pair;

Pair create_pair(int first, int second) {
  Pair p;
  p.first = first;
  p.second = second;
  return p;
}

void bingo(Pair p[], int nums[], int n, int T){
	int row[5] = {5, 5, 5, 5, 5};
  int col[5] = {5, 5, 5, 5, 5};
  int ULDR = 5, URDL = 5;
  for(int i = 0; i < n; ++i){
    int row_num = p[nums[i]].first;
    int col_num = p[nums[i]].second;
    if(--row[row_num] == 0){
      printf("Case #%d: %d\n", T, i+1);
      return;
    }
    if(--col[col_num] == 0){
      printf("Case #%d: %d\n", T, i+1);
      return;
    }
    if(row_num == col_num){
      if(--ULDR == 0){
        printf("Case #%d: %d\n", T, i+1);
        return;
      } 
    }
    if(row_num+col_num == 4){
      if(--URDL == 0){
        printf("Case #%d: %d\n", T, i+1);
        return;
      }
    }
  }
  /*
  for(int i = 0; i < 5; ++i){ printf("row[%d] = %d\n", i, row[i]); }
  for(int i = 0; i < 5; ++i){ printf("col[%d] = %d\n", i, col[i]); }
  printf("ULDR = %d\n", ULDR);
  printf("URDL = %d\n", URDL);
  */
  printf("Case #%d: Not yet \\(^o^)/\n", T);
}

int main(){
	Pair p[26];
  for(int i = 0; i < 5; ++i){
    int a,b,c,d,e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    int j = 0;
    p[a] = create_pair(i, j++);
    p[b] = create_pair(i, j++);
    p[c] = create_pair(i, j++);
    p[d] = create_pair(i, j++);
    p[e] = create_pair(i, j++);
  }
  int T; scanf("%d", &T);
  int case_num = 0;
  while(T--){
    int n; scanf("%d", &n);
    int nums[n];
    for(int i = 0; i < n; ++i){ scanf("%d", &nums[i]); }
    bingo(p, nums, n, ++case_num);
  }

	return 0;
}