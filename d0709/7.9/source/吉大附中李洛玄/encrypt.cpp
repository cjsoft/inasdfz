#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
char s[MAXN];int len;
int sa[MAXN];
int rank[MAXN];
int height[MAXN];
int cnt[MAXN];
int val[MAXN];
int newval[MAXN];
int q[MAXN];
__attribute__((__optimize__("-O2"))) inline bool Is_same(int a,int b,int hl)
{
	return val[a]==val[b]&&
	((a+hl>=len&&b+hl>=len)||
	(a+hl<len&&b+hl<len&&val[a+hl]==val[b+hl]));
}
int rmq[19][MAXN];
int lg[MAXN];
__attribute__((__optimize__("-O2"))) void Get_sa()
{
	int lim=26;
	int i,j,k;
	for(i=0;i<lim;i++)cnt[i]=0;
	for(i=0;i<len;i++)cnt[val[i]=s[i]-'a']++;
	for(i=1;i<lim;i++)cnt[i]+=cnt[i-1];
	for(i=len-1;~i;i--)sa[--cnt[val[i]]]=i;
	int hl,h=0;
	for(hl=1;lim^len;hl<<=1,h=0)
	{
		for(i=0;i<len;i++)if(sa[i]+hl>=len) q[h++]=sa[i];
		for(i=0;i<len;i++)if(sa[i]>=hl) q[h++]=sa[i]-hl;
		for(i=0;i<lim;i++)cnt[i]=0;
		for(i=0;i<len;i++)cnt[val[q[i]]]++;
		for(i=1;i<lim;i++)cnt[i]+=cnt[i-1];
		for(i=len-1;~i;i--)sa[--cnt[val[q[i]]]]=q[i];
		lim=0;
		for(i=0;i<len;lim++)
		{
			for(j=i;j<len&&Is_same(sa[j],sa[j+1],hl);j++);
			for(k=i,i=j+1;k<=j;k++)newval[sa[k]]=lim;
		}
		for(int i=0;i<len;i++)val[i]=newval[i];
	}
	for(int i=0;i<len;i++)rank[sa[i]]=i;
	for(k=0,i=0;i<len;i++)
	{
		k=k?k-1:0;
		if(rank[i]) for(j=sa[rank[i]-1];s[i+k]==s[j+k];k++);
		height[rank[i]]=k;
	}
	for(int i=0;i<len;i++)rmq[0][i]=height[i];
	for(int i=1;i<=18;i++)
		for(int j=0;j+(1<<i-1)<len;j++)
			rmq[i][j]=min(rmq[i-1][j],rmq[i-1][j+(1<<i-1)]);
	lg[1]=0;
	for(int i=2;i<=len;i++)
		lg[i]=lg[i>>1]+1;
}
__attribute__((__optimize__("-O2"))) inline int Ask(int x,int y)
{
	if(x==y) return len;
	if(x>y) swap(x,y);
	x++;
	int len=lg[y-x+1];
	return min(rmq[len][x],rmq[len][y-(1<<len)+1]);
}
__attribute__((__optimize__("-O2"))) set<int>Set;
typedef set<int>::iterator iter;
int tr[MAXN<<2];
__attribute__((__optimize__("-O2"))) void Build(int l,int r,int rt)
{
	tr[rt]=len;
	if(l==r) return;
	int mid=l+r>>1;
	Build(l,mid,rt<<1);
	Build(mid+1,r,rt<<1|1);
}
__attribute__((__optimize__("-O2"))) void Update(int pos,int l=0,int r=len-1,int rt=1)
{
	tr[rt]=min(tr[rt],sa[pos]);
	if(l==r) return;
	int mid=l+r>>1;
	if(pos<=mid) Update(pos,l,mid,rt<<1);
	else Update(pos,mid+1,r,rt<<1|1);
}
__attribute__((__optimize__("-O2"))) int Query(int x,int y,int l=0,int r=len-1,int rt=1)
{
	if(Ask(l,x)>=y&&Ask(r,x)>=y) return tr[rt];
	int mid=l+r>>1;
	int re=len;
	if(x<=mid||Ask(x,mid)>=y) re=min(re,Query(x,y,l,mid,rt<<1));
	if(mid<x||Ask(x,mid+1)>=y) re=min(re,Query(x,y,mid+1,r,rt<<1|1));
	return re;
}
__attribute__((__optimize__("-O2"))) int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s);len=strlen(s);
	Get_sa();Build(0,len-1,1);
	for(int i=0;i<len;)
	{
		if(!Set.size())
		{
			printf("-1 %d ",s[i]);
			Set.insert(rank[i]),Update(rank[i]);
			i++;
			continue;
		}
		iter r=Set.upper_bound(rank[i]);
		if(r==Set.begin())
		{
			int R=Ask(rank[i],*r);
			if(R)
			{
				printf("%d %d ",R,Query(rank[i],R));
				for(int j=i;j<i+R;j++)
					Set.insert(rank[j]),Update(rank[j]);
				i+=R;
			}
			else printf("-1 %d ",s[i]),Set.insert(rank[i]),Update(rank[i]),i++;
		}
		else if(r==Set.end())
		{
			iter l=r;l--;
			int L=Ask(*l,rank[i]);
			if(L)
			{
				printf("%d %d ",L,Query(rank[i],L));
				for(int j=i;j<i+L;j++)
					Set.insert(rank[j]),Update(rank[j]);
				i+=L;
			}
			else printf("-1 %d ",s[i]),Set.insert(rank[i]),Update(rank[i]),i++;
		}
		else
		{
			iter l=r;l--;
			int R=Ask(rank[i],*r);
			int L=Ask(*l,rank[i]);
			if(!L&&!R) printf("-1 %d ",s[i]),Set.insert(rank[i]),Update(rank[i]),i++;
			else if(R>L)
			{
				printf("%d %d ",R,Query(rank[i],R));
				for(int j=i;j<i+R;j++)
					Set.insert(rank[j]),Update(rank[j]);
				i+=R;
			}
			else
			{
				printf("%d %d ",L,Query(rank[i],L));
				for(int j=i;j<i+L;j++)
					Set.insert(rank[j]),Update(rank[j]);
				i+=L;
			}
		}
	}
	return 0;
}
