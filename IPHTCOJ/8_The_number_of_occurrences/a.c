#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool match(char pattern[], char s[], int start_pos){
	for(int i = 0; i < strlen(pattern); ++i){
    if(pattern[i] != s[start_pos + i]){
        return false;
    }
  }
	return true;
}

int find_occ(char pattern[], char s[]){
	int occ = 0;
  for(int i = 0; i <= strlen(s)-strlen(pattern); ++i){
    if(match(pattern, s, i)){
      occ++;
    }
  }
	return occ;
}

int main(){
	char pattern[5];
  scanf("%s", pattern);
  int n;
  scanf("%d", &n);
  
  int max_occ = 0;
  for(int i = 0; i < n; ++i){
    char tmp[9];
      scanf("%s", tmp);
      int cur_occ = find_occ(pattern, tmp);
      if(cur_occ > max_occ){
        max_occ = cur_occ;
      }
  }
  printf("%d", max_occ);
  
  return 0;
}