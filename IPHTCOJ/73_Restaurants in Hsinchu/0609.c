#include <stdio.h>
#define ll long long
#define MOD ((int)1e9+7)

typedef struct _Matrix{
    int mat[2][2];
}Matrix;

Matrix matrix_mul(Matrix A, Matrix B){
    Matrix C;
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < 2; ++k){
                C[i][k] = A[i][j]*B[j][k];
            }
        }
    }
    return C;
}

Matrix Identity(){
    Matrix I;
    I.mat = {{1,0},{0,1}};
    return I;
}

Matrix fsp(Matrix x, int y){
    if(y == 1) return Identity();
    Matrix tmp = fsp(x, y/2);
    if(y % 2 == 1) return matrix_mul(matrix_mul(tmp,tmp), x);
    else return matrix_mul(tmp,tmp);
}

int F(ll i){
    if(i == 1) return 1;
    else if(i == 2) return 2;
    else{
        Matrix x, p, res;
        x.mat[2][2] = {{0, 1},{1, 1}};
        p.mat[2][2] = {{1, 0},{1, 0}};
        res = matrix_mul(fsp(x, i-2), p);
        return res.mat[1][0];
    }
}

int main(){
    ll i;
    while(scanf("%lld" != EOF)){
        printf("%d", F(i));
    }

    return 0;
}