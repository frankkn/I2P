#include <stdio.h>
#include <math.h>

int main() {
    double x, y, prod, ans;
    int z;
    scanf("%lf %lf %d", &x, &y, &z);
    
    prod = x * y;
    
    // round to z-th place
    ans = round(prod * pow(10, z)) / pow(10, z);

    printf("%.10g\n", ans);
    return 0;
}
