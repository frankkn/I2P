#include <stdio.h>

int F[(int)1e5] = {0}; // F[i]: number of (x+y==i)

int main(){
    int T; scanf("%d", &T);
    while(T--){
        memset(F, 0, sizeof(F));
        int A, B, C, D; scanf("%d%d%d%d", &A, &B, &C, &D);
        for(int x = A; x <= B; ++x){
            F[x+A]++;
            F[x+B+1]--;
        }
        for(int i = A+B; i <= B+C+1; ++i){
            F[i] += F[i-1];
        }
        int ans = 0;
        // check i > z ( i = A+B ~ B+C )
        for(int z = B+C; z <= C+D; ++z){
            for(int i = A+B; i <= B+C; ++i){
                if(i > z){
                    ans += F[i];
                }
            }
        }
    
        printf("%d\n", ans);
    }

    return 0;
}