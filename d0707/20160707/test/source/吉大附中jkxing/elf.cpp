#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,l,D;
ll a[50],c[50],dp[2][41][1<<17],ans,p=1,x;
int nxt[50],pos[45],vis[45],suf[45],sure[45],tim;
bool check(ll t)
{
	int i=0,j=0;
	while(i<40)
	{
		if(j==-1||(t>>(39-i)&1)==(x>>(l-1-j)&1)) i++,j++;
		else j=nxt[j];
		if(j==l) return 1;
	}
	return 0;
}	
void dfs(int now,ll f,int d,int id)
{
	if(d&&check(f)) ans++;
	if(now==id) return;
	dfs(now+1,f,0,id);
	dfs(now+1,f^a[now],1,id);
}
int trans(int p,ll t,int x,int y,int z)
{
	if(p==l) return l;
	int i=(x>=0)?sure[x]:39;
	while(i>sure[y])
	{
		if(p==-1||((t>>i&1)^(z>>pos[i]&1))==((x>>l-1-p)&1)) i--,p++;
		else p=nxt[p];
		if(p==l) return l;
	}
	return p;
}
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	cin>>n;
	int i,j,k,id;
	for(i=0;i<n;i++)
	for(j=0;j<40;j++)
	{
		scanf("%1d",&k);
		a[i]=(a[i]<<1)|k;
	}
	cin>>l;
	for(x=0,i=0;i<l;i++) scanf("%1d",&j),x=(x<<1)|j;
	nxt[0]=k=-1;j=0;
	while(j<l)
	{
		if(k==-1||(x>>(l-1-j)&1)==(x>>(l-1-k)&1)) nxt[++j]=++k;
		else k=nxt[k];
	}
	for(id=0,i=39;i>=0;i--,id++)
	{
		for(j=id;j<n&&!(a[j]>>i&1);j++);
		if(j==n) {id--;continue;}
		sure[id]=i;vis[i]=1;
		if(j!=id) swap(a[j],a[id]);
		for(j=id+1;j<n;j++) if(a[j]>>i&1) a[j]^=a[id];
	}
	for(i=id;i<n;i++) p<<=1;
	if(x==0)
	{
		printf("%lld\n",p);
		return 0;
	}
	if(id<25) dfs(0,0,1,id);
	else
	{
		for(i=0;i<n;i++) 
		for(j=39;j>=0;j--)
		if(!vis[j]) c[i]=(c[i]<<1)+(a[i]>>j&1);
		for(i=0;i<40;i++) 
		{
			if(!vis[i]) pos[i]=tim++;
			else pos[i]=50,suf[i]=tim;
		}
		sure[id]=-1;
		dp[0][trans(0,0,-1,0,0)][0]=1;
		for(i=0;i<id;i++)
		{
			memset(dp[D^=1],0,sizeof(dp[D]));
			ll tmp;
			for(j=0;j<=l;j++)
			for(k=0;k<(1<<suf[i]);k++)
			if(tmp=dp[D^1][j][k])
			{
				dp[D][trans(j,0,i,i+1,k)][k&((1<<suf[sure[i+1]])-1)]+=tmp;
				dp[D][trans(j,a[i],i,i+1,k)][(k^c[i])&((1<<suf[sure[i+1]])-1)]+=tmp;
			}	
		}
		ans=dp[D][l][0];
	}
	printf("%lld\n",ans*p);
}