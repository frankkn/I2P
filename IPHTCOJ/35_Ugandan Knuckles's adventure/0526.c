#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[101][1001];

int cmp(const void * a, const void * b)
{
	char ab[2003], ba[2003];
    strcpy(ab, (char*) a);
    strcpy(ba, (char*) b);
    strcat(ab, (char*) b);
    strcat(ba, (char*) a);
    // if ab > ba we need to return -1, strcmp(ba, ab) will return -1
    return strcmp(ba, ab);
}

int main(){
	int n;
  while(scanf("%d", &n) != EOF){
    for(int i = 0; i < n; ++i){
      scanf("%s", str[i]);
    }
    qsort(str, n, sizeof(str[0]), cmp);
    char ans[1000003] = "";
    for(int i = 0; i < n; ++i){
      strcat(ans, str[i]);
    }
    printf("%s\n", ans);
  }
	return 0;
}