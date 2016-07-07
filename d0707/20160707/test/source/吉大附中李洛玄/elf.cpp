#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char buf[45];
ll a[45];
int l;
ll S;
int N;
bool v[40];
void Gauss()
{
	for(int j,i=0;i<40;i++)
	{
		for(j=N;j<n;j++)
			if(a[j]>>i&1)
				break;
		if(j<n)
		{
			if(j^N) swap(a[j],a[N]);
			for(j=0;j<n;j++)if(a[j]>>i&1) if(j^N) a[j]^=a[N];
			N++;
			v[i]=1;
		}
	}
}
ll ans;
void DFS(int now,ll val)
{
	if(now==N)
	{
		for(int x=0;x<=40-l;x++)
			if(((val>>x)&((1<<l)-1))==S)
			{
				ans++;
				break;
			}
		return;
	}
	DFS(now+1,val);
	DFS(now+1,val^a[now]);
}
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",buf);
		for(int j=0;j<40;j++)a[i]=a[i]<<1|(buf[j]=='1');
	}
	scanf("%d",&l);
	scanf("%s",buf);
	for(int i=0;i<l;i++)S=S<<1|(buf[i]=='1');
	Gauss();
	DFS(0,0);
	ans*=1<<(n-N);
	printf("%lld\n",ans);
	return 0;
}
