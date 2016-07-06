#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int maxn=100005;
int a,b,c,g[maxn],n,r[maxn],ans[maxn],fa[maxn],num,test;
bool del[maxn],btm[maxn];
struct side {
	int t,next;
}t[maxn*2];

struct node {
	int x,deep;
}f[maxn];

inline void add(int a,int b) {
	t[num].t=b; t[num].next=r[a]; r[a]=num++;
}

void work_mark(int x,int deep) {
	f[x].x=x; f[x].deep=deep;
	for (int i=r[x];i!=-1;i=t[i].next)
		work_mark (t[i].t,deep+1);
}

int cmp1(const void *a,const void *b) {
	if ((*(node *)b).deep>(*(node *)a).deep) return 1;
	return -1;
}

void check_change() {
	for (int i=1;i<=n;i++) {
		int x=f[i].x;
		if (g[x]!=0) {
			del[x]=true;
			if (g[x]<0) g[fa[x]]--; else g[fa[x]]++;
		}
	}
}

void work(int x,int s) {
	if (s>0) return;
	if (btm[x]&&g[x]==0) ans[++ans[0]]=x;
	for (int i=r[x];i!=-1;i=t[i].next)
		work (t[i].t,s+g[x]);
}

int cmp2(const void *a,const void *b) {
	if (*(int *)a>*(int *)b) return 1;
	return -1;
}

int main() {
	freopen ("ah.in","r",stdin);
	freopen ("ah.out","w",stdout);
	scanf ("%d",&test);
	while (test--) {
		scanf ("%d",&n); num=0;
		memset (r,-1,sizeof (r));
		memset (del,false,sizeof (del));
		memset (btm,true,sizeof (btm));
		for (a=1;a<=n;a++) {
			scanf ("%d",&fa[a]);
			add (fa[a],a); btm[fa[a]]=false;
		}
		for (a=1;a<=n;a++) {
			scanf ("%d",&g[a]);
			if (g[a]==0) g[a]=1;
			else if (g[a]==1) g[a]=-1;
				else g[a]=0;
		}
		work_mark (1,1);
		qsort (f+1,n,sizeof (node),cmp1);
		check_change ();
		if (del[1]) {
			if (g[1]<0) printf ("-1\n");
			else {
				for (a=1,b=0;a<=n;a++)
					if (btm[a]&&g[a]==0) b++;
				printf ("%d ",b);
				for (a=1;a<=n;a++)
					if (btm[a]&&g[a]==0)
						printf ("%d ",a);
				printf ("\n");
			}
			continue;
		}
		ans[0]=0; work (1,0);
		qsort (ans+1,ans[0],sizeof (int),cmp2);
		for (a=0;a<=ans[0];a++)
			printf ("%d ",ans[a]);
		printf ("\n");
	}
	return 0;
}
