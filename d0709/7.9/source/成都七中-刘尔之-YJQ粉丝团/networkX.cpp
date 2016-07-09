#include<cstdio>
#include<iostream>
#define N 100001
using namespace std;

int b[10*N],p[N],a[10*N];
int u[N],v[N],c[N];
int sz[N],f[N],siz[N];
int to[2*N],nx[2*N],cc[2*N],et,h[N];
int s[N],fa[N],gc[N];
int ff(int u){return f[u]^u?f[u]=ff(f[u]):u;}
void hb(int u,int v){
	if(siz[ff(u)]>siz[ff(v)])swap(u,v);
	if(f[u]^f[v])
		siz[f[v]]+=siz[f[u]],f[f[u]]=f[v];
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	freopen("network.in","r",stdin);
	for(int i=2;i<=1000000;i++){
		if(!b[i])p[++p[0]]=i,a[i]=p[0];
		for(int j=1;j<=p[0]&&p[j]*i<=1000000;j++)
			if(b[i*p[j]]=1,a[i*p[j]]=j,i%p[j]==0)break;
	}
	int n,q;scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u[i],&v[i],&c[i]);
		for(int z=c[i];z^1;){sz[a[z]]++;
			for(int zz=p[a[z]];z%zz==0;z/=zz);}
	}
	scanf("%d",&q);q++;
	for(;q--;){
		int m=1;et=0;
		for(int i=2;i<=p[0];i++)if(sz[i]>sz[m])m=i;
		for(int i=1;i<=n;i++)f[i]=i,h[i]=0,siz[i]=1;
		for(int i=1;i<n;i++)if(c[i]%p[m]==0)hb(u[i],v[i]);
		for(int i=1;i<n;i++)if(ff(u[i])^ff(v[i]))
			to[++et]=f[v[i]],nx[et]=h[f[u[i]]],h[f[u[i]]]=et,cc[et]=c[i],
			to[++et]=f[u[i]],nx[et]=h[f[v[i]]],h[f[v[i]]]=et,cc[et]=c[i];
		long long ans=0;
		for(int o=1;o<=n;o++)if(f[o]==o){
			fa[o]=gc[o]=0;
			for(s[s[0]=1]=o;s[0];){int u=s[s[0]--],v;
				if(gc[u]==1)continue;ans+=siz[u]*siz[o];
				for(int i=h[u];i;i=nx[i])if((v=to[i])^fa[u])
					fa[v]=u,s[++s[0]]=v,gc[v]=gcd(gc[u],cc[i]);
			}
		}
		cout<<(1ll*n*n-ans>>1)<<"\n";
		if(!q)break;
		int k,d;scanf("%d%d",&k,&d);
		for(int z=c[k];z^1;){sz[a[z]]--;
			for(int zz=p[a[z]];z%zz==0;z/=zz);}
		for(int z=c[k]=d;z^1;){sz[a[z]]++;
			for(int zz=p[a[z]];z%zz==0;z/=zz);}
	}
}
