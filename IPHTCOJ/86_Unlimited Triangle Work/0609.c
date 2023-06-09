#include <stdio.h>
#include <string.h>
#define ll long long
#define min(a,b) ((a)<(b)?(a):(b))

int F[(int)1e6] = {0};

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(F, 0, sizeof(F));
        int A, B, C, D;
        scanf("%d%d%d%d", &A, &B, &C, &D);
        for (int x = A; x <= B; ++x) {
            F[x + B]++;
            F[x + C + 1]--;
        }
        for (int i = A + B; i <= B + C + 1; ++i) {
            F[i] += F[i - 1];
            //printf("F[%d]: %d\n", i, F[i]);
        }
        ll ans = 0;
        // check i > z ( i = A+B ~ B+C)
        for (int i = A + B; i <= B + C; ++i) {
            if (i > C) {
                ans += F[i] * min(i-C, D-C+1); // F[i] * z有幾種可能
            }
        }
        /* check i > z ( i = A+B ~ B+C)
        for (int i = C + 1; i <= B + C; ++i) {
            ans += F[i] * min(i-C, D-C+1); // F[i] * z有幾種可能
        }
        */
        printf("%lld\n", ans);
    }
    return 0;
}