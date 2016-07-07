#include <cstdio>
const int N=2005;
char s[5];
int T,n,OK,tot,tota,ans,a[N],st[N],pos[N],tim[N];
struct node{
	int l,r,ls,rs,sum[2];
}t[N];
void Build(int x,int l,int r)
{
	t[x].l=l;t[x].r=r;
	t[x].sum[0]=t[x].sum[1]=0;
	if(l==r)
	{
		t[x].ls=t[x].rs=0;return;
	}
	int mid=l+r>>1;
	Build(t[x].ls=++tot,l,mid);
	Build(t[x].rs=++tot,mid+1,r);
}
void Add(int x,int p,int c,int v)
{
//	if(x==1) printf("%d %d %d\n",p,c,v);
	t[x].sum[c]+=v;
	if(t[x].l==t[x].r) return;
	if(p<=(t[x].l+t[x].r>>1)) Add(t[x].ls,p,c,v);
	else Add(t[x].rs,p,c,v);
}
int First(int x,int l,int r,int c)
{
	if(!t[x].sum[c]||l>r) return 0;
	if(t[x].l==t[x].r) return t[x].l;
	int mid=t[x].l+t[x].r>>1,answer=0;
	if(l<=mid) answer=First(t[x].ls,l,r,c);
	if(!answer&&r>mid) answer=First(t[x].rs,l,r,c);
	return answer;
}
int Last(int x,int l,int r,int c)
{
	if(!t[x].sum[c]||l>r) return 0;
	if(t[x].l==t[x].r) return t[x].l;
	int mid=t[x].l+t[x].r>>1,answer=0;
	if(r>mid) answer=Last(t[x].rs,l,r,c);
	if(!answer&&l<=mid) answer=Last(t[x].ls,l,r,c);
	return answer;
}
int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		OK=1;ans=tota=0;
		for(int i=1;i<=2000;i++) pos[i]=-1,tim[i]=0;
		scanf("%d",&n);
		Build(tot=1,1,n);
		for(int i=1,x,y;i<=n;i++)
		{
			scanf("%s%d",s,&x);
			if(!OK) continue;
			y=(s[0]=='E');
			if(!x) Add(1,i,y,1);
			else if(pos[x]!=y)
			{
				if(pos[x]==-1&&!y) a[++tota]=i;
				pos[x]=y;tim[x]=i;
			}
			else
			{
				int z=First(1,tim[x],i-1,!y);
				if(!z) OK=0;
				else Add(1,z,!y,-1),pos[x]=y;
			}
		}
		if(!OK) puts("OTHER");
		else
		{
			for(int i=1;i<=2000;i++)
				if(pos[i]==1)
				{
					int y=First(1,tim[i]+1,n,0);
					if(!y) ans++;
					else Add(1,y,0,-1);
				}
			for(int i=1;i<=tota;i++) Add(1,a[i],0,1);
			for(int x=Last(1,1,n,1);x;x=Last(1,1,x-1,1))
			{
				int y=First(1,x+1,n,0);
				if(!y) ans++;
				else Add(1,y,0,-1);
			}
			printf("%d\n",ans);
		}
	}
}
