#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 30010
#define MAXM 5
#define MOD 998244353
#define mod(x) while(x>=MOD)x-=MOD;
using namespace std;
inline int read()
{
	int x=0,t=1,c;
	while(!isdigit(c=getchar()))if(c=='-')t=-1;
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*t;
}
int cnt[MAXM],A[MAXN];
int Process(int L,int R,int K)
{
	int ans=0;
	for(int i=0;i<K;i++)cnt[i]=1;
	for(int i=L;i<=R;i++)
	{
		int &h=cnt[A[i]];
		ans+=h;
		mod(ans);
		for(int j=0;j<K;j++)
		{
			if(j!=A[i])cnt[j]+=h;
			mod(cnt[j]);
		}
	}
	return ans;
}
void solve()
{
	int n=read(),K=read(),m=read();
	for(int i=1;i<=n;i++)A[i]=read()%K;
	for(int i=0;i<m;i++)
	{
		int t=read(),l=read(),r=read(),x;
		if(t==1)
		{
			x=read();
			for(int i=l;i<=r;i++)
			{
				A[i]+=x;
				while(A[i]>=K)A[i]-=K;
			}
		}
		else if(t==2)
		{
			x=read();
			for(int i=l;i<=r;i++)
			{
				A[i]*=x;
				while(A[i]>=K)A[i]-=K;
			}
		}
		else if(t==3)
		{
			printf("%d\n",Process(l,r,K));
		}
	}
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int T=read();
	while(T--)solve();
}
