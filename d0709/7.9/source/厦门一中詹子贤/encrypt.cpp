#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

const int N=500005;
const int M=750005;

struct Sam
{
	int maxx,son[26];
}sam[M];

struct Edge
{
	int to,nxt;
}edge[M];


int n,m,root,las,t[M*4],siz[M],top[M],fir[M],fa[M],son[M],dep[M],tot,dfn[M],id[N];
char s[N];

void addedge(int x,int y)
{
	edge[tot]=(Edge) {y,fir[x]}; fir[x]=tot++;
}

void add(int x)
{
	int np=++m,p=las; las=np;
	sam[np].maxx=sam[p].maxx+1;
	while ((p)&&(!sam[p].son[x]))
	{
		sam[p].son[x]=np;
		p=fa[p];
	}
	if (!p) {fa[np]=root; return;}
	int q=sam[p].son[x];
	if (sam[q].maxx==sam[p].maxx+1) {fa[np]=q; return;}
	int nt=++m; 
	sam[nt]=sam[q]; fa[nt]=fa[q]; sam[nt].maxx=sam[p].maxx+1; fa[np]=fa[q]=nt;
	while ((p)&&(sam[p].son[x]==q))
	{
		sam[p].son[x]=nt;
		p=fa[p];
	}
}

void dfs1(int x)
{
	siz[x]=0; son[x]=top[x]=x; dep[x]=dep[fa[x]]+1;
	for (int i=fir[x]; i!=-1; i=edge[i].nxt)
	{
		dfs1(edge[i].to);
		if (siz[edge[i].to]>siz[son[x]]) son[x]=edge[i].to;
		siz[x]+=siz[edge[i].to];
	}
	siz[x]++;
}

void dfs2(int x)
{
	dfn[x]=++dfn[0]; 
	if (son[x]==x) return;
	top[son[x]]=top[x];
	dfs2(son[x]);
	for (int i=fir[x]; i!=-1; i=edge[i].nxt)
	  if (edge[i].to!=son[x])
	    dfs2(edge[i].to);
}

void build_tree(int l,int r,int x)
{
	t[x]=m+1; 
	if (l==r) return;
	int mid=(l+r)/2;
	build_tree(l,mid,x*2);
	build_tree(mid+1,r,x*2+1);
}


void build_sam()
{
	n=strlen(s); m=root=las=1;
	for (int i=n-1; i>=0; i--)
	{
		add(s[i]-'a');
//		for (int j=1; j<=m; j++) cout << j << ' ' << "t=" << sam[j].son['t'-'a'] << ' ' << "q=" << sam[j].son['q'-'a'] << ' ' << fa[j] << ' '<< sam[j].maxx << endl; cout << endl;	 cout << las << endl;
		id[i]=las;
	}
	memset(fir,-1,sizeof(fir)); tot=0;
	for (int i=m; i>1; i--) addedge(fa[i],i);
		
	
	dfs1(1);
	dfs2(1);
	build_tree(1,m,1);
}

int Lca(int u,int v)
{
	int fu=top[u],fv=top[v];
	while (fu!=fv)
	{
		if (dep[fu]<dep[fv]) {swap(fu,fv); swap(u,v);}
		u=fa[fu];
		fu=top[u];
	}
	if (dep[u]>dep[v]) swap(u,v);
	return u;
}

void change(int l,int r,int x,int y)
{
//	cout << "        " << l << ' ' << r << ' ' << x <<endl;
	t[x]=y; 
	if (l==r) return;
	int mid=(l+r)/2;
	if (dfn[id[y]]<=mid) change(l,mid,x*2,y); else
						 change(mid+1,r,x*2+1,y);
	t[x]=y;
	if (t[x*2]<t[x]) t[x]=t[x*2];
	if (t[x*2+1]<t[x]) t[x]=t[x*2+1];
}

int query_l(int l,int r,int x,int y)
{
	if (t[x]==m+1) return t[x];
	if (l==r) return t[x];
	int mid=(l+r)/2;
	if (y<=mid) return query_l(l,mid,x*2,y); else
	{
		int ret=query_l(mid+1,r,x*2+1,y); 
		if (ret!=m+1) return ret;
		return query_l(l,mid,x*2,y);
	}
}

int query_r(int l,int r,int x,int y)
{
	if (t[x]==m+1) return t[x];
//	cout << l << ' ' << r << ' ' << t[x] << 'b' << endl;
	if (l==r) return t[x];
	int mid=(l+r)/2;
	if (y>mid) return query_r(mid+1,r,x*2+1,y); else
	{
		int ret=query_r(l,mid,x*2,y); 
		if (ret!=m+1) return ret;
		return query_r(mid+1,r,x*2+1,y);
	}
}

int query(int l,int r,int ll,int rr,int x)
{
	if (t[x]==m+1) return t[x];
	if ((l==ll)&&(r==rr)) return t[x];
	int mid=(l+r)/2;
	if (rr<=mid) return query(l,mid,ll,rr,x*2); else
	if (ll>mid) return query(mid+1,r,ll,rr,x*2+1); else
	{
		int lx=query(l,mid,ll,mid,x*2),rx=query(mid+1,r,mid+1,rr,x*2+1);
		return min(lx,rx);
	}
}

int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s);
	build_sam();
	int j=0;
	for (int i=0; i<n; i++)
	{
		if (j==n) break;
//			cout << query_r(1,m,1,m) << ' ';
		if (i==j)
		{
			int lx=query_l(1,m,1,dfn[id[i]]),rx=query_r(1,m,1,dfn[id[i]]);
//			cout << i << ' ' << j << ' ' << lx << ' ' << rx << 'a' << endl;
			if ((lx==m+1)&&(rx==m+1))
			{
				printf("-1 %d ",((int) (s[i])));
				j++; 
			}
			else
			{
				int lca=0;
				if (lx!=m+1) lca=Lca(id[lx],id[i]); 
				if (rx!=m+1) 
				{
					int tmp=Lca(id[rx],id[i]);
					if (dep[tmp]>dep[lca]) lca=tmp;
				}
				if (lca==1) 
				{
					printf("-1 %d ",((int) (s[i])));
					j++;
				}
				else
				{
//					cout << endl << lca << ' ' << m << ' ' << query(1,m,dfn[lca],dfn[lca]+siz[lca]-1,1) << endl;
					printf("%d %d ",sam[lca].maxx,query(1,m,dfn[lca],dfn[lca]+siz[lca]-1,1));
					j+=sam[lca].maxx;
				}
			}
		}
		change(1,m,1,i);
	}
	printf("\n");
	return 0;
}
