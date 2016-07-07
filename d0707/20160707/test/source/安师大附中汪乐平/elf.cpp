#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define ll long long
ll a[50],M,b,ans;
int n,m,i,j;
char s[50];
void out(ll x,int y)
{
	if(y)out(x>>1,y-1);
	putchar((x&1)^'0');
}
void dfs(int x,ll y)
{
	if(x==n)
	{
		for(int i=0;i<m;i++,y>>=1)if(!(y&M^b))
		{
			ans++;
			return;
		}
		return;
	}
	dfs(x+1,y);
	dfs(x+1,y^a[x]);
}
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		for(j=0;j<40;j++)a[i]=(a[i]<<1)|(s[j]^'0');
	}
	for(i=39;~i;i--)
	{
		for(j=39-i;j<40;j++)if((a[j]>>i)&1)break;
		if(j==40)continue;
		if(j!=39-i)swap(a[j],a[39-i]);
		for(j=40-i;j<40;j++)if((a[j]>>i)&1)a[j]^=a[39-i];
	}
	for(i=0;i<40;i++)if((a[39-i]>>i)&1)for(j=0;i+j<39;j++)if((a[j]>>i)&1)a[j]^=a[39-i];
	sort(a,a+40,greater<ll>());
	for(i=0;i<40;i++)if(!a[i])break;
	n=i;
	scanf("%d%s",&m,s);
	M=(1ll<<m)-1;
	for(i=0;i<m;i++)b=(b<<1)|(s[i]^'0');
	m=41-m;
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}

