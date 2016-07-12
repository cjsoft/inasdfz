
#include<iostream>
#include<cstdio>
using namespace std;
int MOD,INF,N,A[110];
int GOOD(int x)
{
	int i,r;
	r=0;
	for (i = 1; i <= x; i = i + 1)
		r = (r + x) % MOD;
	return r;
}
int LUCK(int x)
{
	int i,r;
	r=0;
	for (i = 1; i <= x; i = i + 1)
		r = (r + GOOD(x)) % MOD;
	return r;
}
int AND(int x)
{
	int i,r;
	r=0;
	for (i = 1; i <= x; i = i + 1)
		r = (r + LUCK(x)) % MOD;
	return r;
}
int HAVE(int x)
{
	int i,r;
	r=0;
	for (i = 1; i <= x; i = i + 1)
		r = (r + AND(x)) % MOD;
	return r;
}
int FUN(int x)
{
	int i,r;
	r=0;
	for (i = 1; i <= x; i = i + 1)
		r = (r + HAVE(x)) % MOD;
	return r;
}
int main()
{
	freopen("233.in","r",stdin);
	freopen("thefall9.out","w",stdout);
  INF = 1000000000;

  cin >> N >> MOD;
  int i;
  for (i = 1; i <= N; i = i + 1) {
    cin >> A[i];
	int ans=1;
	for(int j=1;j<=6;j++)  ans=((long long)ans*A[i])%MOD;
	printf("%d\n",ans);
}
}



