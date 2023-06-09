#include <stdio.h>
#include <stdlib.h>
#define ll long long

typedef struct _Obj
{
    int a, b;    
}Obj;

Obj arr[(int)1e5+3];

int cmp(const void *a, const void *b){
    Obj aa = *(Obj *) a;
    Obj bb = *(Obj *) b;
    
    if( (aa.a - aa.b) < (bb.a - bb.b) ) return -1;
    else if( (aa.a - aa.b) > (bb.a - bb.b) )return 1;
    else return 0;
    
    //return (aa.a - aa.b) - (bb.a - bb.b);
}

int main(){
    int n, k; scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i)  scanf("%d", &arr[i].a);
    for(int i = 0; i < n; ++i)  scanf("%d", &arr[i].b);
    
    qsort(arr, n, sizeof(arr[0]), cmp);
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        if(i < k || arr[i].a < arr[i].b) ans += arr[i].a;
        else ans += arr[i].b;
    }
    printf("%lld\n", ans);

    return 0;
}