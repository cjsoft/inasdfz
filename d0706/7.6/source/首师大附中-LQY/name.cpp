#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read()
{
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
int A[2005][2],ans[2005];
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	int n=read();
	long long res=0;
	for(int i=1;i<=n;i++) A[i][0]=read();
	for(int i=1;i<=n;i++) A[i][1]=read();
	int m=read();
	while(m--)
	{
		int L=read(),R=read(),T=read();
		for(int i=L;i<=R;i++)
			if(A[i][ans[i]]<=T)	ans[i]^=1;
	}
	for(int i=1;i<=n;i++) res+=A[i][ans[i]];
	printf("%lld\n",res);
	return 0;
}

