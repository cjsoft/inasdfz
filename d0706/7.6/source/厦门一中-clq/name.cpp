#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define nMax 100010
using namespace std;
int n,a[nMax][2],b[nMax],m;
struct s_1
{
	int l,r,t;
}din[nMax];
struct Node
{
	int v,Max;
	Node *son[2];
	Node(){son[0]=son[1]=NULL; v=Max=0;}
}*root[nMax];
void update(Node *now,Node *old,int l,int r,int id,int v,int Max)
{
	*now=*old;
	now->v+=v; now->Max=max(now->Max,Max);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(id<=mid) update(now->son[0]=new Node(),old->son[0],l,mid,id,v,Max);
	if(id>mid) update(now->son[1]=new Node(),old->son[1],mid+1,r,id,v,Max);
}
void ask(Node *now,int l,int r,int al,int ar,int &sum,int &Max)
{
	if(al<=l&&r<=ar) {sum=now->v; Max=now->Max; return;}
	int mid=(l+r)>>1;
	int s=0,m=0;
	sum=0; Max=0;
	if(al<=mid) ask(now->son[0],l,mid,al,ar,s,m);
	sum+=s; Max=max(Max,m);
	if(ar>mid) ask(now->son[1],mid+1,r,al,ar,s,m);
	sum+=s; Max=max(Max,m);
}
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i][0]);
	for(int i=1;i<=n;i++) scanf("%d",&a[i][1]); memset(b,0,sizeof(b));
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	scanf("%d%d%d",&din[i].l,&din[i].r,&din[i].t);
	if(n<10000)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=din[i].l;j<=din[i].r;j++) if(a[j][b[j]]<=din[i].t) b[j]^=1;
		}
		long long ans=0;
		for(int i=1;i<=n;i++) ans+=a[i][b[i]];
		printf("%lld\n",ans);
		return 0;
	}
	root[0]=new Node(); root[0]->son[0]=root[0]->son[1]=root[0];
	root[m+1]=root[0];
	for(int i=m;i>0;i--)
	update(root[i]=new Node(),root[i+1],1,1000000000,din[i].t,1,i);
	memset(b,0,sizeof(b));
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][0]==a[i][1]) {ans+=a[i][0]; continue;}
		int id,ls;
		ask(root[1],1,1000000000,min(a[i][0],a[i][1]),max(a[i][0],a[i][1])-1,ls,id);
		if(id>0)
		if(a[i][1]>a[i][0]) b[i]=1; else b[i]=0;
		ask(root[id+1],1,1000000000,a[i][b[i]],1000000000,ls,id);
		b[i]^=(ls&1);
		ans+=a[i][b[i]];
	}
	printf("%lld\n",ans);
	return 0;
}
