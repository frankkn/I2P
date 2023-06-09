#include <stdio.h>
#include <string.h>
#define ll long long
#define MOD ((ll)1e9+7)

typedef struct _Matrix
{
  ll mat[3][3];
} Matrix;

Matrix matrix_mul(Matrix L, Matrix R){
  // retrun L * R
  Matrix res;
  memset(res.mat, 0, sizeof(res.mat));
  for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j) for(int k = 0; k < 3; ++k){
    (res.mat[i][k] += (L.mat[i][j] * R.mat[j][k] % MOD) % MOD);
  }
  return res;
}

Matrix Identity(){
  Matrix res;
  memset(res.mat, 0, sizeof(res.mat));
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      if(i == j){
        res.mat[i][j] = 1;
      }
    }
  }
  return res;
}


Matrix fast_power(Matrix x, ll y){
  if(y == 0) return Identity();
  Matrix tmp = fast_power(x, y/2);
  if(y % 2 == 1) return matrix_mul(matrix_mul(tmp,tmp), x);
  else return matrix_mul(tmp,tmp);
}

Matrix init_x(Matrix x){
  int values[3][3] = {{0, 1, 0}, {0, 0, 1}, {1, 2, 1}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      x.mat[i][j] = values[i][j];
    }
  }
  return x;
}

Matrix init_P(Matrix P){
  int values[3][3] = {{1, 0, 0}, {12, 0, 0}, {13, 0, 0}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      P.mat[i][j] = values[i][j];
    }
  }
  return P;
}

int P(ll i){
  if(i == 1) return 1;
  else if(i == 2) return 12;
  else if(i == 3) return 13;
  else{
    Matrix x, res, P, ans;
    x = init_x(x);
    res = fast_power(x, i-3);
    P = init_P(P);
    ans = matrix_mul(res, P);
    return ans.mat[2][0] % MOD;
  }
}

int main(){
  int t; scanf("%d", &t);
  while(t--){
    ll i; scanf("%lld", &i);
    printf("%d\n", P(i));
  }
  return 0;
}