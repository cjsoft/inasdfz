#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=500010;
struct seg
{
	int mx,low,high;
}t[N*4];
int n,m,x,y,z,ans,len,inf=10000000;
int s[N],ss[N],xx[N],yy[N],sa[N],sa1[N],s1[N],h[N],rank[N],mx[N][20],B[N];
char ch[N];
void SA(int m)
{
	int p,i,j,k;
	for(i=1;i<=n;i++) xx[i]=ch[i];
	for(k=1;k<=n;k<<=1)
	{
		for(i=1;i<=m;i++) s[i]=ss[i]=0;
		for(i=1;i<=n;i++) s[xx[i]]++;
		for(i=1;i<=m;i++) s[i]+=s[i-1];
		for(i=1;i<=n;i++)
		{
			if(i+k<=n) yy[i]=xx[i+k];
			else yy[i]=0;
			ss[yy[i]]++;
		}
		for(i=1;i<=m;i++) ss[i]+=ss[i-1];
		for(i=1;i<=n;i++) sa1[ss[yy[i]]--]=i;
		for(i=n;i;i--) sa[s[xx[sa1[i]]]--]=sa1[i];
		for(i=1;i<=n;i++) s1[i]=xx[i];
		p=2;
		xx[sa[1]]=1;
		for(i=2;i<=n;i++)
			if(s1[sa[i-1]]==s1[sa[i]]&&yy[sa[i-1]]==yy[sa[i]]) xx[sa[i]]=p-1;
			else xx[sa[i]]=p++;
		if(p>n) break;
		m=p;
	}
	for(i=1;i<=n;i++) rank[sa[i]]=i;
	k=0;
	for(i=1;i<=n;i++)
	{
		if(k) k--;
		j=sa[rank[i]-1];
		while(i+k<=n&&j+k<=n&&ch[i+k]==ch[j+k]) k++;
		h[rank[i]]=k;
	}
}
void pre_rmq()
{
	int i,j,a;
	for(i=1;i<=18;i++)
		B[1<<i]=i;
	for(i=1;i<=n;i++)
		B[i]=max(B[i],B[i-1]);
	for(i=1;i<=n;i++)
		mx[i][0]=h[i];
	for(j=1;j<=19;j++)
		for(i=1;i<=n;i++)
			mx[i][j]=min(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
}
int rmq(int l,int r)
{
	if(l>r) return 0;
	int len=(r-l+1),a=B[len];
//	printf("%d\n",a);
	return min(mx[l][a],mx[r-(1<<a)+1][a]);
}
int find_low(int x,int l,int r,int L,int R)
{
	if(L>R) return 0;
	if(l==L&&r==R) return t[x].low;
	int mid=(l+r)/2,id;
	id=find_low(x*2,l,mid,L,min(mid,R));
	if(id) return id;
	return find_low(x*2+1,mid+1,r,max(L,mid+1),R);
}
int find_high(int x,int l,int r,int L,int R)
{
	if(L>R) return 0;
	if(l==L&&r==R) return t[x].high;
	int mid=(l+r)/2,id;
	id=find_high(x*2+1,mid+1,r,max(L,mid+1),R);
	if(id) return id;
	return find_high(x*2,l,mid,L,min(mid,R));
}
void add(int x,int l,int r,int xx,int s)
{
	if(!t[x].low) t[x].low=xx;
	else t[x].low=min(t[x].low,xx);
	if(!t[x].high) t[x].high=xx;
	else t[x].high=max(t[x].high,xx);
	if(!t[x].mx) t[x].mx=s;
	else t[x].mx=min(t[x].mx,s);
	if(l==r) return;
	int mid=(l+r)/2;
	if(xx<=mid) add(x*2,l,mid,xx,s);
	else add(x*2+1,mid+1,r,xx,s);
}
int query(int x,int l,int r,int L,int R)
{
	if(L>R) return inf;
	if(l==L&&r==R)
	{
		if(t[x].mx) return t[x].mx;
		else return inf;
	}
	int mid=(l+r)/2;
	return min(query(x*2,l,mid,L,min(mid,R)),query(x*2+1,mid+1,r,max(L,mid+1),R));
}
int solve_l(int x)
{
	int l=1,r=x,mid;
	while(l<r-1)
	{
		int mid=(l+r)/2;
		if(rmq(mid+1,x)>=ans) r=mid;
		else l=mid;
	}
	if(rmq(l+1,x)>=ans) return l;
	else return r;
}
int solve_r(int x)
{
	int l=x,r=n,mid;
	while(l<r-1)
	{
		int mid=(l+r)/2;
		if(rmq(x+1,mid)>=ans) l=mid;
		else r=mid;
	}
	if(rmq(x+1,r)>=ans) return r;
	else return l;
}
int main()
{
	int a,b,c,i,j,l,r;
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",ch+1);
	n=strlen(ch+1);
	SA(256);
//	for(i=1;i<=n;i++)
//		printf("%d %d\n",sa[i],h[i]);
	pre_rmq();
	i=1;
	while(i<=n)
	{
		x=rank[i];
		a=find_high(1,1,n,1,x-1);
		b=find_low(1,1,n,x+1,n);
		//printf("a,b:%d %d\n",a,b);
		ans=0;
		if(a) ans=max(ans,rmq(a+1,x));
		if(b) ans=max(ans,rmq(x+1,b));
		if(!ans)
		{
			printf("-1 %d ",ch[i]);
			add(1,1,n,rank[i],i);
			i++;
			continue;
		}
		l=solve_l(x);
		r=solve_r(x);
		a=query(1,1,n,l,r);
		printf("%d %d ",ans,a-1);
		for(j=i;j<i+ans;j++)
			add(1,1,n,rank[j],j);
		i+=ans;
	}
//	printf("%d\n",rmq(6,8));
}
