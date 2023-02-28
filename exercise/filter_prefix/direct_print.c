#include <stdio.h>
#include <string.h>

int compare(char *p, char *s) {
    for(int i = 0; i < strlen(p) - 1; ++i) {
        if(p[i] != s[i]) return 0;
    }
    return 1;
}

int main()
{
    char p[501];
    char s[501];
    
    scanf("%s", p);
    while(scanf("%s", s) != EOF) {
        if(!compare(p,s)) printf("%s\n", s);
    }

    return 0;
}