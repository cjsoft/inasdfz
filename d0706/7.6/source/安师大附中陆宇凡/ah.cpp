#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;

int ans,s[100005];
int T,i,j,bh[100005],tt;
int n,f[100005],h[100005];

struct node
{
	int v,next;
}L[200005];

void jia(int u,int v)
{
	tt++;
	L[tt].v=v;L[tt].next=h[u],h[u]=tt;
//	tt++;
//	L[tt].v=u;L[tt].next=h[v],h[v]=tt;
}

void work(int a)
{
	int i,b,t=0;
//	if(bh[a]==-1)bh[a]=0;
	if(h[a])bh[a]=0;
	for(i=h[a];i;i=L[i].next)
	{
		b=L[i].v;
	//	if(b==f[a])continue;
		work(b);
		t+=bh[b];
	}
	if(t>0)bh[a]=1;
	if(t<0)bh[a]=-1;
//		if(bh[a]==-1&&!z[a])ans[++ans[0]]=a;
//		bh[a]=0;
}

int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)
			f[i]=h[i]=0,bh[i]=0;
		tt=0;ans=0;s[0]=0;
		for(i=1;i<=n;i++) scanf("%d",&f[i]),jia(f[i],i);//z[f[i]]++;
		for(i=1;i<=n;i++) {scanf("%d",&bh[i]);}//if(bh[i]==1)printf("(%d %d %d %d %d %d %d)",z[f[f[f[i]]]],f[f[f[i]]],z[f[f[i]]],f[f[i]],z[f[i]],f[i],i);
		for(i=1;i<=n;i++)
		{
			if(bh[i]==1)continue;
			if(bh[i]==-1){bh[i]=0;if(!h[i])ans++;continue;}
			bh[i]=-1;
		}
		work(1);
		if(bh[1]==1)printf("-1\n");
		else 
		{
			if(n*ans>1e7)printf("0\n");
			else
			{
				for(i=1;i<=n;i++)
				{
					if(h[i]||bh[i])continue;
					bh[i]=-1;
					work(1);
					if(bh[1]==-1)
						s[++s[0]]=i;
					bh[i]=0;
				}
//				sort(s+1,s+s[0]+1);
				for(i=0;i<=s[0];i++)
					printf("%d ",s[i]);
				printf("\n");
			}
		}
	}
	return 0;
}
