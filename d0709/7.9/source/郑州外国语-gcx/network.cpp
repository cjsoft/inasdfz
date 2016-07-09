#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=7005;
int n,Q;
struct E{
	int to,next,w;
}e[N*2];int heade[N],tope;
void adde(int u,int v,int w)
{
	++tope;e[tope].to=v;e[tope].w=w;e[tope].next=heade[u];heade[u]=tope;
}

int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
int ans=0;
void dfs(int wz,int ff,int w)
{
	if(w>1) ans++;
	int tt;
	for(int i=heade[wz];i;i=e[i].next)
		if(e[i].to!=ff)
		{
			tt=gcd(e[i].w,w);
			if(tt>1) dfs(e[i].to,wz,tt); 
		}
}
int Sum,Ans;
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&n);Sum=n*(n-1)/2;
	for(int i=1,uu,vv,ww;i<n;++i)
		scanf("%d%d%d",&uu,&vv,&ww),
		adde(uu,vv,ww),adde(vv,uu,ww);
	for(int i=1;i<=n;++i)
		dfs(i,0,0);
	ans/=2;
	printf("%d\n",Sum-ans);
	scanf("%d",&Q);
	
	
	int k1,x1;
	while(Q--)
	{
		ans=0;
		scanf("%d%d",&k1,&x1);
		e[k1*2].w=e[k1*2-1].w=x1;
		for(int i=1;i<=n;++i)
		dfs(i,0,0);
		ans/=2;	
		printf("%d\n",Sum-ans);
	}
	/*Ans=ans;
	int k1,x1,uu,vv,ww,a1,a2;
	while(Q--)
	{
		scanf("%d%d",&k1,&x1);
		uu=e[k1*2].to;vv=e[k1*2-1].to;
		ww=e[k1*2].w;	
		ans=0;dfs(uu,vv,ww);a1=ans;
		ans=0;dfs(vv,uu,ww);a2=ans;
		Ans-=a1*a2;
		e[k1*2].w=e[k1*2-1].w=x1;
		ww=x1;
	//	cout<<uu<<" "<<vv<<endl;
		ans=0;dfs(uu,vv,ww);a1=ans;
		ans=0;dfs(vv,uu,ww);a2=ans;
		Ans+=a1*a2;
		printf("%d\n",Sum-Ans);
	}*/
	return 0;
}

