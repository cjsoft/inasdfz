#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 1000005
#define ll long long
char getc(){
    static char *S,*T,buf[65536];
    if(S==T){T=(S=buf)+fread(buf,1,65536,stdin);if(S==T) return EOF;}
    return *S++;
}
int read(){
    static char ch;static int D;
    while(!isdigit(ch=getc()));
    for(D=ch-'0';isdigit(ch=getc());) D=D*10+ch-'0';
    return D;
}
int n,Q,Tim;
int u[N],v[N],w[N][105];
int id[105],c[105],use[N];
int fa[N],siz[N];
int mu[M],pri[M],rk[M],st[M],top,cnt;
bool vis[M];
vector<int> v1[M],v2[M];
pair<int,int> op[1005];
ll ans[105];
ll calc(ll x){return x*(x-1)/2;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int find2(int x){return fa[x]==x?x:find2(fa[x]);}
void work(int k)
{
	if(!v1[k].size()&&!v2[k].size()) return;
	ll ret=0;
	for(int x,i=0;i<v1[k].size();i++) 
	{
		x=v1[k][i];
		fa[u[x]]=u[x];siz[u[x]]=1;
		fa[v[x]]=v[x];siz[v[x]]=1;
	}
	for(int x,i=0;i<v2[k].size();i++) 
	{
		x=id[v2[k][i]];
		fa[u[x]]=u[id[v2[k][i]]];siz[u[x]]=1;
		fa[v[x]]=v[id[v2[k][i]]];siz[v[x]]=1;
	}
	for(int i=1;i<=Q;i++) fa[id[i]]=id[i],siz[id[i]]=1;
	for(int i=0;i<v1[k].size();i++) 
	{	
		int p=find(u[v1[k][i]]),q=find(v[v1[k][i]]);
		if(p==q) continue;
		if(siz[p]<siz[q]) swap(p,q);
		ret-=calc(siz[p])+calc(siz[q]);
		siz[p]+=siz[q];fa[q]=p;
		ret+=calc(siz[p]);
	}
	for(int i=0;i<=Q;i++)
	{
		int tot=0,j;ll tmp=ret;
		for(int t=0;t<v2[k].size();t++)
		if((j=v2[k][t])!=i&&w[id[j]][i]%st[k]==0)
		{
			int p=find2(u[id[j]]),q=find2(v[id[j]]);
			if(p==q) continue;
			if(siz[p]<siz[q]) swap(p,q);
			op[++tot]=make_pair(p,q);
			tmp-=calc(siz[p])+calc(siz[q]);
			siz[p]+=siz[q];fa[q]=p;
			tmp+=calc(siz[p]);
		}
		if(i&&c[i]%st[k]==0)
		{
			int p=find2(u[id[i]]),q=find2(v[id[i]]);
			if(p!=q) tmp-=(calc(siz[p])+calc(siz[q])-calc(siz[p]+siz[q]));
		}
		ans[i]+=mu[st[k]]*tmp;
		while(tot) 
			siz[op[tot].first]-=siz[op[tot].second],fa[op[tot].second]=op[tot].second,tot--;
	}
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	n=read();mu[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(!vis[i]) pri[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt&&pri[j]*i<=1000000;j++)
		{
			vis[i*pri[j]]=1;
			if(i%pri[j]==0) break;
			mu[i*pri[j]]=-mu[i];
		}
	}
	for(int i=1;i<=1000000;i++) if(mu[i]) st[++top]=i,rk[i]=top;
	for(int i=1;i<n;i++) u[i]=read(),v[i]=read(),w[i][0]=read();
	Q=read();
	for(int i=1;i<n;i++) for(int j=1;j<=Q;j++) w[i][j]=w[i][j-1];
	int tot=0;
	for(int i=1;i<=Q;i++) 
	{
		id[i]=read();c[i]=read();use[id[i]]++;
		for(int j=i;j<=Q;j++) w[id[i]][j]=c[i];
	}
	for(int i=1;i<n;i++)
	if(!use[i])
	{
		for(int j=1;j*j<=w[i][0];j++)
		if(w[i][0]%j==0)
		{
			if(mu[j]) v1[rk[j]].push_back(i);
			if(j*j!=w[i][0]&&mu[w[i][0]/j]) 
				v1[rk[w[i][0]/j]].push_back(i);
		}
	}
	for(int i=1;i<=Q;i++)
	{
		for(int k=0;k<=Q;k++)
		if(k==0||w[id[i]][k]!=w[id[i]][k-1])
		{
			for(int j=1;j*j<=w[id[i]][k];j++)
			if(w[id[i]][k]%j==0)
			{
				if(mu[j]) v2[rk[j]].push_back(i);
				if(j*j!=w[id[i]][k]&&mu[w[id[i]][k]/j]) 
					v2[rk[w[id[i]][k]/j]].push_back(i);
			}
		}
	}
	for(int i=1;i<=top;i++) work(i);
	for(int i=0;i<=Q;i++) printf("%lld\n",ans[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
