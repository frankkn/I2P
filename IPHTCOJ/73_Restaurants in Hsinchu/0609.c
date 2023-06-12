#include <stdio.h>
#define ll long long
#define MOD ((int)1e9+7)

typedef struct _Matrix{
    ll mat[2][2];
}Matrix;

Matrix matrix_mul(Matrix A, Matrix B){
    Matrix C;
    memset(C.mat, 0, sizeof(C.mat));
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < 2; ++k){
                (C.mat[i][k] += (A.mat[i][j] * B.mat[j][k] % MOD)) % MOD;
            }
        }
    }
    return C;
}

Matrix Identity(){
    Matrix I;
    memset(I.mat, 0, sizeof(I.mat));
    int values[2][2] = {{1,0},{0,1}};
    for(int i = 0; i < 2; ++i){
    	for(int j = 0; j < 2; ++j){
        	I.mat[i][j] = values[i][j];
        }
    }
    return I;
}

Matrix init_x(Matrix x){
    int values[2][2] = {{0,1},{1,1}};
    for(int i = 0; i < 2; ++i){
    	for(int j = 0; j < 2; ++j){
        	x.mat[i][j] = values[i][j];
        }
    }
    return x;
}

Matrix init_p(Matrix p){
    int values[2][2] = {{1,0},{1,0}};
    for(int i = 0; i < 2; ++i){
    	for(int j = 0; j < 2; ++j){
        	p.mat[i][j] = values[i][j];
        }
    }
    return p;
}

Matrix fsp(Matrix x, ll y){
    if(y == 0) return Identity();
    Matrix tmp = fsp(x, y/2);
    if(y % 2 == 1) return matrix_mul(matrix_mul(tmp,tmp), x);
    else return matrix_mul(tmp,tmp);
}

int F(ll i){
    if(i == 1) return 1;
    else if(i == 2) return 1;
    else{
        Matrix x, p, res;
        x = init_x(x);
        p = init_p(p);
        res = matrix_mul(fsp(x, i-2), p);
        return res.mat[1][0] % MOD;
    }
}

int main(){
    ll i;
    while( scanf("%lld", &i) != EOF){
        printf("%d\n", F(i));
    }

    return 0;
}