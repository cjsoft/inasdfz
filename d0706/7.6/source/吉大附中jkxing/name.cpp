#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define inf 1000000000
int n,m,a[2][N],l[N],r[N],t[N],pos[N],root,tot;
int b[N<<1],top;
vector<int> v[N];
vector< pair<int,int> > LL[N],RR[N];
int siz[N<<3],mx[N<<3],rt[N<<3];
int L[N*40],R[N*40],val[N*40],rnd[N*40],sz[N*40],cnt;
void pushup(int x){sz[x]=sz[L[x]]+sz[R[x]]+1;}
void lturn(int &k)
{
	int t=R[k];R[k]=L[t];L[t]=k;
	sz[t]=sz[k];pushup(k);k=t;
}
void rturn(int &k)
{
	int t=L[k];L[k]=R[t];R[t]=k;
	sz[t]=sz[k];pushup(k);k=t;
}
void insert(int &x,int v)
{
	if(!x){x=++cnt;sz[x]=1;val[x]=v;rnd[x]=rand();return;}
	sz[x]++;
	if(val[x]<v) 
	{
		insert(R[x],v);
		if(rnd[R[x]]<rnd[x]) lturn(x);
	}
	else 
	{
		insert(L[x],v);
		if(rnd[L[x]]<rnd[x]) rturn(x);
	}
}
void del(int &x,int v)
{
	if(val[x]==v)
	{
		if(!L[x]||!R[x]) x=L[x]+R[x];
		else if(rnd[L[x]]<rnd[R[x]]) rturn(x),del(x,v);
		else lturn(x),del(x,v);
		return;
	}
	sz[x]--;
	if(val[x]<v) del(R[x],v);
	else del(L[x],v);
}
int findmx(int x)
{
	while(R[x]) x=R[x];
	return val[x];
}
int find(int x,int v)
{
	int ret=0;
	while(x)
	{
		if(val[x]==v) return ret+1+sz[R[x]];
		else if(val[x]>v) ret+=sz[R[x]]+1,x=L[x];
		else x=R[x];
	}
	return ret;
}
void add(int l,int r,int x,int p,int v=0)
{
	insert(rt[x],v);siz[x]++;mx[x]=max(mx[x],v);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(p<=mid) add(l,mid,x<<1,p,v);
	else add(mid+1,r,x<<1|1,p,v);
}
void del(int l,int r,int x,int p,int v=0)
{
	del(rt[x],v);
	mx[x]=findmx(rt[x]);
	siz[x]--;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(p<=mid) del(l,mid,x<<1,p,v);
	else del(mid+1,r,x<<1|1,p,v);
	mx[x]=max(mx[x<<1],mx[x<<1|1]);
	siz[x]=siz[x<<1]+siz[x<<1|1];
}
int get_mx(int l,int r,int x,int L,int R)
{
	if(!x) return 0;
	if(L==l&&R==r) return mx[x];
	int mid=(l+r)>>1;
	if(R<=mid) return get_mx(l,mid,x<<1,L,R);
	else if(L>mid) return get_mx(mid+1,r,x<<1|1,L,R);
	else return max(get_mx(l,mid,x<<1,L,mid),get_mx(mid+1,r,x<<1|1,mid+1,R));
}
int query(int l,int r,int x,int p,int v)
{
	if(!x) return 0;
	if(l==r) return find(rt[x],v);
	int mid=(l+r)>>1;
	if(p>mid) return query(mid+1,r,x<<1|1,p,v);
	else return query(l,mid,x<<1,p,v)+find(rt[x<<1|1],v);
}
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",a[0]+i),b[++top]=a[0][i];
	for(int i=1;i<=n;i++) scanf("%d",a[1]+i),b[++top]=a[1][i];
	cin>>m;
	sort(b+1,b+top+1);
	top=unique(b+1,b+top+1)-b-1;
	for(int i=1;i<=m;i++) 
	{
		scanf("%d%d%d",l+i,r+i,t+i);
		t[i]=upper_bound(b+1,b+top+1,t[i])-b-1;
		LL[l[i]].push_back(make_pair(t[i],i));
		RR[r[i]].push_back(make_pair(t[i],i));
	}
	long long ans=0;
	for(int i=1;i<=n;i++) 
	{
		int mx=max(a[0][i],a[1][i]),mn=min(a[0][i],a[1][i]);
		int rmx=lower_bound(b+1,b+top+1,mx)-b;
		int rmn=lower_bound(b+1,b+top+1,mn)-b;
		for(int j=0;j<LL[i].size();j++) add(1,top,1,LL[i][j].first,LL[i][j].second);
		pos[i]=get_mx(1,top,1,rmn,rmx-1);
		if(pos[i]==m) ans+=max(a[0][i],a[1][i]);
		else
		{
			int k=query(1,top,1,rmx,pos[i]+1);
			if(pos[i]==0) ans+=a[k&1][i];
			else ans+=(k&1)?mn:mx;
		}
		for(int j=0;j<RR[i].size();j++) 
			del(1,top,1,RR[i][j].first,RR[i][j].second);
	}
	cout<<ans<<endl;
}
