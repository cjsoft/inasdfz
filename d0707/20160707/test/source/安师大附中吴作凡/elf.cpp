#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <set>
#include      <map>
using namespace std;

typedef long long LL;
const int N=45;

int n,m,L,pos[N],next[N],Nexus[N][12][1<<11],p2[N];
bool ok[N][11][1<<11];
LL w,a[N];

void get(LL Num,int l,int r,int& p,bool& o)
{
	while(l<r)
	{
		int len=min(10,r-l);
		o|=ok[p+1][len][(Num>>l)&((1<<len)-1)];p=Nexus[p+1][len][(Num>>l)&((1<<len)-1)];
		l+=len;
	}
}

map<LL,LL> H[N][N];

LL dfs(int i,int p,LL Num,bool o)
{
	if(o)
		return 1ll<<m-i;
	if(i==n)
	{
		if(p==L-1||o)
			return 1;
		return 0;
	}
	if(H[i][p+1].count(Num>>pos[i]))
		return H[i][p+1][Num>>pos[i]];
	int nxt=p;bool O=o;
	get(Num,pos[i],pos[i+1],nxt,O);LL Ans=dfs(i+1,nxt,Num,O);
	nxt=p,O=o;
	get(Num^a[i],pos[i],pos[i+1],nxt,O);Ans+=dfs(i+1,nxt,Num^a[i],O);
	return H[i][p+1][Num>>pos[i]]=Ans;
}

void Gauss()
{
	for(int i=0;i<40;i++)
	{
		int p=m;
		while(p<n&&!((a[p]>>i)&1))
			p++;
		if(p==n)
			continue;
		if(p!=m)
			swap(a[p],a[m]);
		for(int j=0;j<n;j++)
			if(((a[j]>>i)&1)&&j!=m)
				a[j]^=a[m];
		pos[m]=i;m++;
	}
	pos[m]=40;
}

void getnext()
{
	next[0]=-1;
	int j=-1;
	for(int i=1;i<L;i++)
	{
		while(j!=-1&&((w>>i)&1)!=((w>>j+1)&1))
			j=next[j];
		if(((w>>i)&1)==((w>>j+1)&1))
			j++;
		next[i]=j;
	}
	for(int i=0;i<=L;i++)
		for(int l=0;l<=10;l++)
			for(int k=0;k<(1<<l);k++)
			{
				int j=i-1;
				if(j==L-1)
				{
					ok[i][l][k]=1;continue;
				}
				for(int t=0;t<l;t++)
				{
					while(j!=-1&&((k>>t)&1)!=((w>>j+1)&1))
						j=next[j];
					if(((k>>t)&1)==((w>>j+1)&1))
						j++;
					if(j==L-1)
					{
						ok[i][l][k]=1;break;
					}
				}
				Nexus[i][l][k]=j;
			}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
#endif
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0,k;j<40;j++)
			scanf("%1d",&k),a[i]=a[i]<<1|k;
	}
	cin>>L;
	for(int j=0,k;j<L;j++)
		scanf("%1d",&k),w=w<<1|k;
	Gauss();getnext();
	int nxt=-1;bool o=0;
	get(0,0,pos[0],nxt,o);
	LL Ans=dfs(0,nxt,0,o)<<n-m;
	cout<<Ans<<endl;
	return 0;
}

