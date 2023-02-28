#include <stdio.h>
#include <string.h>

int compare(char* p, char* s){
    for(int i = 0; i < strlen(p); ++i){
        if(p[i] != s[i])    return 0;
    }
    return 1;
}

int main(){
    
    char p[501];
    char s[501];
    char a[501][501];
    int i = 0;
    scanf("%s", p);
    while(scanf("%s",s) != EOF){
        if(compare(p,s)){
            strcpy(a[i++], s);
        }
    }
    
    for(int j=0; j<i; ++j) printf("%s\n", a[j]);
}