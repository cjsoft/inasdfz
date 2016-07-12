#include <bits/stdc++.h>
using namespace std;
#define N 2005
#define M 5005
#define mod 1073741823
int f[N*N],mu[M],pri[M],vis[M],cnt;
int f1[N*N],f2[N*N],g[M];
int a,b,c,ans;
void add(int &x,int y){x+=y;if(x>mod) x&=mod;}
int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	cin>>a>>b>>c;
	if(c==1) swap(a,c);
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			f[i*j]++;
	for(int i=1;i<=a*b;i++)
		for(int j=i;j<=a*b;j+=i)
			add(f1[i],f[j]);
	mu[1]=1;
	for(int i=2;i<=c;i++)
	{
		if(!vis[i]) pri[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt&&pri[j]*i<=c;j++)
		{
			vis[i*pri[j]]=1;
			if(i%pri[j]==0) break;
			mu[i*pri[j]]=-mu[i];
		}
	}
	for(int i=1;i<=c;i++) if(mu[i])
		for(int j=1;i*j<=c;j++) 
			add(g[i],c/(i*j));
	for(int i=1;i<=c;i++) if(mu[i])
		for(int j=i;j<=a*b;j+=i)
			add(f2[j],mu[i]==1?g[i]:mod-g[i]+1);
	for(int i=1;i<=a*b;i++) add(ans,(1ll*f1[i]*f2[i])&mod);
	cout<<ans<<endl;
}
