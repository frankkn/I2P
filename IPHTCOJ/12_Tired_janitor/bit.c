#include <stdio.h>
#define ll long long

ll lowbit(ll x){ return x&-x; }

ll query(ll bit[], ll x){
	ll sum = 0;
  for(;x; x-= lowbit(x)){
    sum += bit[x];
  }
  return sum;
}

void update(int i, int val, ll bit[], ll row_size) {
  for (; i <= row_size; i += lowbit(i))
  bit[i] += val;
}

int main(){
  ll row_size, q;
  scanf("%lld%lld", &row_size, &q);
	ll arr[row_size+1];
  ll bit[row_size+1];
  for(int i = 1; i <= row_size; ++i){
    char str[100];
    scanf("%s", str);
    sscanf(str, "%lld", &arr[i]); // read only digit, removing non-digit part
    char tmp[6];
    scanf("%s", tmp);
  }
    
  for(int i = 1; i <= row_size; ++i){
    bit[i] = 0;
  }

  for(int i = 1; i <= row_size; ++i){
    update(i, arr[i], bit, row_size);
  }
    
	for(int i = 0; i < q; ++i){
    ll L,R;
    scanf("%lld%lld", &L, &R);
    printf("%lld\n", query(bit, R) - query(bit, L-1));    
  }
	return 0;
}