#include<bits/stdc++.h>
#define N 2100
#define seed 13131
#define MEM 25000000
#define lson l,mid,ls[no]
#define rson mid+1,r,rs[no]
using namespace std;
typedef unsigned long long ll;
int n;
struct node
{
	int l,r;
	int root;
}t[N*N/2];
int tot;
int a[N];
int ls[MEM],rs[MEM],size[MEM];
ll h[MEM],pw[N];
int mt;
int newnode(int no)
{
	mt++;
	ls[mt]=ls[no],rs[mt]=rs[no],size[mt]=size[no];
	h[mt]=h[no];
	return mt;
}
int newnode2(int no)
{
	mt++;
	ls[mt]=ls[no],rs[mt]=rs[no];
	return mt;
}
void Pushup(int no)
{
	size[no]=size[ls[no]]+size[rs[no]];
	h[no]=h[ls[no]]+pw[size[ls[no]]]*h[rs[no]];
}
void Insert(int l,int r,int &no,int x)
{
	if(l==r)
	{
		no=newnode(no);
		h[no]+=pw[size[no]]*x;
		size[no]++;
	}
	else
	{
		no=newnode2(no);
		int mid=l+r>>1;
		if(x<=mid)	Insert(lson,x);
		else		Insert(rson,x);
		Pushup(no);
	}
}
bool operator < (node &a,node &b)
{
	if(h[a.root]!=h[b.root])
	{
		static int l,r,mid,noa,nob;
		l=1,r=n,noa=a.root,nob=b.root;
		while(l!=r)
		{
			int mid=l+r>>1;
			if(h[ls[noa]]!=h[ls[nob]])
				r=mid,noa=ls[noa],nob=ls[nob];
			else
				l=mid+1,noa=rs[noa],nob=rs[nob];
		}
		return size[noa]>size[nob];
	}
	return a.l<b.l;
}
int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	int p,q,i,j,k;
	scanf("%d%d%d",&n,&p,&q);
	pw[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		pw[i]=pw[i-1]*seed;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			t[++tot].l=i;
			t[tot].r=j;
			if(i!=j)
				t[tot].root=t[tot-1].root;
			Insert(1,n,t[tot].root,a[j]);
		}
	}
	sort(t+1,t+tot+1);
	for(i=p;i<=q;i++)
		printf("%d %d\n",t[i].l,t[i].r);
	cerr<<clock()<<endl;
	return 0;
}
