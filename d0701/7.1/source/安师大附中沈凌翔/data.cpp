#include <iostream>
#include <cstdio>
using namespace std;
int a,b,c,f[30001],k,l,m,n,r,test,ans,root;
struct tree {
	int l[5];
}t[10000000];

void dfs(int x,int y) {
	if (x==-1) return;
	for (int i=0;i<k;i++)
		dfs (t[x].l[i],y);
	if (t[x].l[y]==-1) {
		t[x].l[y]=++ans;
		t[ans].l[0]=t[ans].l[1]=t[ans].l[2]=t[ans].l[3]=t[ans].l[4]=-1;
	}
}

void calc() {
	ans=0; root=0;
	t[0].l[0]=t[0].l[1]=t[0].l[2]=t[0].l[3]=t[0].l[4]=-1;
	for (;l<=r;l++) dfs (root,f[l]);
}

int main() {
	freopen ("data.in","r",stdin);
	freopen ("data.out","w",stdout);
	scanf ("%d",&test);
	while (test--) {
		scanf ("%d %d %d",&n,&k,&m);
		for (a=1;a<=n;a++)
			scanf ("%d",&f[a]);
		while (m--) {
			scanf ("%d",&a);
			if (a==1) {
				scanf ("%d %d %d",&l,&r,&b);
				for (;l<=r;l++) (f[l]+=b)%=k;
			}
			if (a==2) {
				scanf ("%d %d %d",&l,&r,&b);
				for (;l<=r;l++) (f[l]*=b)%=k;
			}
			if (a==3) {
				scanf ("%d %d",&l,&r);
				calc (); printf ("%d\n",ans);
			}
		}
	}
	return 0;
}
