#include<bits/stdc++.h>
#define A(u,v) e[++t]=v,l[t]=h[u],c[h[u]=t]=s
#define N 200010
using namespace std;
int n,i,t,e[N],l[N],h[N],c[N],s,u,v,q;
void Dfs(int x,int f,int y)
{
	int i=h[x];if(y==1)for(s++;i;i=l[i])if(e[i]^f)Dfs(e[i],x,1);
	if(y^1)for(;i;i=l[i])if(e[i]^f)Dfs(e[i],x,__gcd(y,c[i]));
}
main()
{
	freopen("network.in","r",stdin);freopen("network.out","w",stdout);
	for(cin>>n,i=t=1;i<n;i++)cin>>u>>v>>s,A(u,v),A(v,u);
	for(cin>>q;~q;q--)
	{
		for(s=0,i=1;i<=n;i++)Dfs(i,0,0);cout<<s/2<<endl;
		if(q)cin>>u>>v,c[u*2]=c[u*2+1]=v;
	}
}//kachang
