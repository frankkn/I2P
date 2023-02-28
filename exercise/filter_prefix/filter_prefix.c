#include "stdio.h"
#include "stdlib.h"

int main (void)
{
    int count = 0;
    char s [501];
    char t [501];
    char *a[501] = {'\0'};
    int i = 0;
    scanf("%s", s);
    while (scanf("%s", t) != EOF )
    {
        char *ps = s, *pt = t;
        while (*ps && *pt && *ps == *pt) { ++ps; ++pt; }
        count += (*ps == '\0');
        printf("%d\n", count);
    }
    return 0;
}