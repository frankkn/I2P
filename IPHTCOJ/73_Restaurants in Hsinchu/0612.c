#include <stdio.h>
#include <stdlib.h>
#define MOD ((int)1e9+7)
#define ll long long
typedef struct _Matrix{
	int mat[2][2];
}Matrix;

Matrix mp(Matrix L, Matrix R){
	Matrix m; memset(m.mat, 0, sizeof(m.mat));
    for(int i = 0; i < 2; ++i){
    	for(int j = 0; j < 2; ++j){
        	for(int k = 0; k < 2; ++k){
            	(m.mat[i][k] += (L.mat[i][j] * R.mat[j][k] % MOD)) %MOD;
            }
        }
    }
    return m;
}

Matrix Identity(){
	Matrix m; memset(m.mat, 0, sizeof(m.mat));
	int values[2][2] = {{1,0},{0,1}};
    for(int i = 0; i < 2; ++i){
    	for(int j = 0; j < 2; ++j){
            m.mat[i][j] = values[i][j];
        }
    }
	return m;
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

Matrix fsp(Matrix x, ll n){
	if(n == 0) return Identity();
    Matrix tmp = fsp(x, n/2);
    if(n%2 ==1) return mp(mp(tmp,tmp), x);
    else return mp(tmp,tmp);
}

int F(ll n){
	if(n==1) return 1;
    else if(n==2) return 1;
    else{
    	Matrix x, p, res;
        x = init_x(x);
        p = init_p(p);
        res = mp(fsp(x, n-2), p);
    	return res.mat[1][0] % MOD;
    }

}

int main(){
	ll n; 
    while( scanf("%lld", &n) != EOF ){
    	int ans = F(n);
        printf("%d\n", ans);
    }
	return 0;
}