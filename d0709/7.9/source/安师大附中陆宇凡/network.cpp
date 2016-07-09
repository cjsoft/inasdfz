#include<stdio.h>
#include<iostream>
using namespace std;

bool bh[7005];
int zg[7005][7005],list1[7005];
int k,x,ans,s1,s2,s11,s22,kk,zhu,p,q;
int N,i,j,u,v,w,tt,h[7005],Q,list2[7005];

struct node
{
	int u,v,w,next;
}L[14005];

int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}

void jia(int u,int v,int w)
{
	tt++;
	L[tt].u=u,L[tt].v=v,L[tt].w=w,L[tt].next=h[u],h[u]=tt;
	tt++;
	L[tt].u=v,L[tt].v=u,L[tt].w=w,L[tt].next=h[v],h[v]=tt;
}

int work(int a,int fa,int s)
{
	int i,b,ss=0;
	if(s==1)ss=1;
	zg[zhu][a]=s;
	for(i=h[a];i;i=L[i].next)
	{
		b=L[i].v;
		if(b==fa)continue;
		ss+=work(b,a,gcd(s,L[i].w));
	}
	return ss;
}

void zao(int u,int v)
{
	int tt1=1,tt2=1,p,q,i;
	memset(bh,false,sizeof(bh));
	bh[u]=bh[v]=true;
	list1[0]=list2[0]=0;
	list1[++list1[0]]=u;
	list2[++list2[0]]=v;
	while(tt1<=list1[0])
	{
		p=list1[tt1++];
		for(i=h[p];i;i=L[i].next)
		{
			q=L[i].v;
			if(bh[q])continue;
			bh[q]=true;
			list1[++list1[0]]=q;
		}
	}
	while(tt2<=list2[0])
	{
		p=list2[tt2++];
		for(i=h[p];i;i=L[i].next)
		{
			q=L[i].v;
			if(bh[q])continue;
			bh[q]=true;
			list2[++list2[0]]=q;
		}
	}
}

int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&N);
	for(i=1;i<N;i++)
	{
		scanf("%d %d %d",&u,&v,&w),jia(u,v,w),zg[u][v]=zg[v][u]=w;
//		if(w==1)ans++;
	}
	for(i=1;i<=N;i++)
	{
		zhu=i;
		for(j=h[i];j;j=L[j].next)
			ans+=work(L[j].v,i,L[j].w);
	}
/*	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(!zg[j][i]||i==j)continue;
			for(k=1;k<=N;k++)
			{
				if(!zg[i][k]||zg[j][k]||!zg[i][j]||i==k||j==k)continue;
				zg[j][k]=zg[k][j]=gcd(zg[i][j],zg[i][k]);
				if(zg[k][j]==1)ans++;
			}
		}
	}*/
	ans/=2;
	printf("%d\n",ans);
	scanf("%d",&Q);
	for(i=1;i<=Q;i++)
	{
//		ans=0;
		scanf("%d %d",&k,&x);
		L[2*k].w=L[2*k-1].w=x;
		u=L[2*k].u,v=L[2*k].v;
		if(zg[u][v]==1)ans--;
		zg[u][v]=zg[v][u]=x;
		if(zg[u][v]==1)ans++;
		zao(u,v);
		for(j=1;j<=list1[0];j++)
		{
			p=list1[j];
			if(p!=u&&zg[p][u]==1)continue;
			for(kk=1;kk<=list2[0];kk++)
			{
				q=list2[kk];
				if(q!=v&&zg[q][v]==1)continue;
				if(p==u&&q==v)continue;
				if(zg[p][q]==1)ans--;
				if(p!=u&&q!=v)zg[p][q]=zg[q][p]=gcd(gcd(zg[p][u],zg[q][v]),x);
				else
				{
					if(p==u)zg[p][q]=zg[q][p]=gcd(zg[v][q],x);
					else zg[p][q]=zg[q][p]=gcd(x,zg[p][u]);
				}
				if(zg[p][q]==1)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
