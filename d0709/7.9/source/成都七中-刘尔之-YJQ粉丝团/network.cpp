#include<cstdio>
#include<iostream>
#define N 100001
using namespace std;

int to[2*N],nx[2*N],cc[2*N],et,
	u[N],v[N],c[N],h[N],s[N],fa[N],gc[N];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	int n,q;scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d%d",&u[i],&v[i],&c[i]);
	scanf("%d",&q);q++;
	for(;q--;){et=0;
		for(int i=1;i<=n;i++)h[i]=0;for(int i=1;i<n;i++)
			to[++et]=v[i],nx[et]=h[u[i]],h[u[i]]=et,cc[et]=c[i],
			to[++et]=u[i],nx[et]=h[v[i]],h[v[i]]=et,cc[et]=c[i];
		long long ans=0;
		for(int o=1;o<=n;o++){fa[o]=gc[o]=0;
			for(s[s[0]=1]=o;s[0];){
				int u=s[s[0]--],v;if(gc[u]==1)continue;ans++;
				for(int i=h[u];i;i=nx[i])if((v=to[i])^fa[u])
					fa[v]=u,s[++s[0]]=v,gc[v]=gcd(gc[u],cc[i]);
			}
		}
		cout<<(1ll*n*n-ans>>1)<<"\n";if(!q)break;
		int k,d;scanf("%d%d",&k,&d);c[k]=d;
	}
	return 0;
}
