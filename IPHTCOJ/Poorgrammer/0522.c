#include <stdio.h>
int a[(int)2e5+10];
int n;

int lines(int day)
{
	int cnt = 0, p; // penalty
	for(int i = 0; i < n; ++i)
	{
		p = i / day;
		if(a[i] - p > 0) cnt += (a[i] - p);
	}
	return cnt;
}
int main()
{
	int t;  
	scanf("%d",&t);
	while(t--)
	{
    int m;
		scanf("%d%d",&n,&m);
		for(int i = 0; i < n; ++i) scanf("%d",&a[i]);
		int L = 1, R = n+1;
		while(L < R)
		{
			int M = (L+R)/2;
			if(lines(M) >= m) R = M;
			else L = M + 1;
		}
		if(lines(R) >= m) printf("%d\n", R);
		else printf("-1\n");
	}
	return 0;
}