#include <bits/stdc++.h>
using namespace std;
namespace R
{
	__attribute__((__optimize__("-O2"))) inline char Getc()
	{
		static const int LEN=1<<15;
		static char buf[LEN],*S=buf,*T=buf;
		if(S==T)
		{
			T=(S=buf)+fread(buf,1,LEN,stdin);
			if(S==T) return EOF;
		}
		return *S++;
	}
	__attribute__((__optimize__("-O2"))) inline int Read()
	{
		static char ch;
		static int D;
		while(!isdigit(ch=Getc()));
		for(D=ch-'0';isdigit(ch=Getc());)D=(D<<1)+(D<<3)+ch-'0';
		return D;
	}
}
const int N=1000005;
int n,q;
int x[N],y[N],z[N],a[110],c[110],del[N];
int p[N],sign[N];
vector<int>Del,val;
vector<pair<int, int> >b[N];
long long res[N],cur;
__attribute__((__optimize__("-O2"))) void Pre()
{
	p[1]=1;
	for(int i=1;i<N;i++)sign[i]=1;
	for(int i=2;i<N;i++)
		if(!p[i])
			for(int j=i;j<N;j+=i)
			{
				if(!p[j])p[j]=i;
				sign[j]*=-1;
			}
}
__attribute__((__optimize__("-O2"))) void Gen(int id,int t,int val)
{
	vector<int>x;
	x.push_back(1);
	while(val>1)
	{
		int u=p[val];
		while(val%u==0)val/=u;
		int sz=x.size();
		for(int i=0;i<sz;i++)x.push_back(x[i]*u);
	}
	for(int i=0;i<x.size();i++)b[x[i]].push_back(make_pair(t,id));
}
int root[N];
vector<pair<int,int> >backup;
__attribute__((__optimize__("-O2"))) long long C2(int u){return 1ll*u*(u-1)>>1;}
__attribute__((__optimize__("-O2"))) int Getroot(int u){return root[u]<0?u:Getroot(root[u]);}
__attribute__((__optimize__("-O2"))) void Join(int u,int v,int nb)
{
	u=Getroot(u);v=Getroot(v);
	if(root[u]<root[v]) swap(u,v);
	if(nb) backup.push_back(make_pair(u,root[u])),backup.push_back(make_pair(v,root[v]));
	cur-=C2(-root[u])+C2(-root[v]);
	root[v]+=root[u];
	cur+=C2(-root[v]);
	root[u]=v;
}
__attribute__((__optimize__("-O2"))) void Restore()
{
	for(int i=backup.size()-1;i>=0;i--)
		root[backup[i].first]=backup[i].second;
	backup.clear();
}
__attribute__((__optimize__("-O2"))) void Go(int id)
{
	if(b[id].empty()) return;
	cur=0;
	for(int i=0;i<b[id].size();i++)
	{
		int u=x[b[id][i].second];
		int v=y[b[id][i].second];
		root[u]=-1,root[v]=-1;
	}
	int lasttime=0;
	for(int i=0;i<b[id].size();)
	{
		long long foores=cur;
		int times=b[id][i].first;
		int last=i;
		while(last<(int)b[id].size()&&b[id][last].first==times)last++;
		for(int j=lasttime;j<times;j++)res[j]+=cur*sign[id];
		for(int j=i;j<last;j++)
		{
			int xx=b[id][j].second;
			Join(x[xx],y[xx],times>-1);
		}
		if(times>=0) res[times]+=cur*sign[id],Restore(),cur=foores;
		i=last;lasttime=times+1;
	}
	for(int i=lasttime;i<=q;i++)res[i]+=cur*sign[id];
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	using R::Read;
	Pre();
	n=Read();
	for(int i=1;i<n;i++)x[i]=Read(),y[i]=Read(),z[i]=Read();
	q=Read();
	for(int i=1;i<=q;i++)
	{
		a[i]=Read(),c[i]=Read();
		if(!del[a[i]]) del[a[i]]=1,Del.push_back(a[i]);
	}
	val.resize(Del.size());
	sort(Del.begin(),Del.end());
	for(int i=1;i<n;i++)if(del[i])val[lower_bound(Del.begin(),Del.end(),i)-Del.begin()]=z[i];
	for(int i=1;i<n;i++)if(!del[i])Gen(i,-1,z[i]);
	for(int i=0;i<Del.size();i++)Gen(Del[i],0,val[i]);
	for(int i=1;i<=q;i++)
	{
		val[lower_bound(Del.begin(),Del.end(),a[i])-Del.begin()]=c[i];
		for(int j=0;j<Del.size();j++)Gen(Del[j],i,val[j]);
	}
	for(int i=1;i<N;i++)Go(i);
	for(int i=0;i<=q;i++)printf("%lld\n",res[i]);
	return 0;
}
