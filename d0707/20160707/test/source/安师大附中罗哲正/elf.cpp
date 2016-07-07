#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
#define next next_
typedef long long LL;
const int S=40;
int n,m,r,L;
LL a[40],b[40],w,ans;
int next[45],tr[45][2];
void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int t,j=0;j<S;j++)
			scanf("%1d",&t),a[i]|=LL(t)<<j;
	}
	scanf("%d",&L);
	for(int t,j=0;j<L;j++)
		scanf("%1d",&t),w|=LL(t)<<j;
	next[0]=-1;
	for(int i=1,j,c;i<=L;i++)
	{
		c=w>>i-1&1;
		for(j=next[i-1];j!=-1&&(w>>j&1)!=c;j=next[j]);
		next[i]=j+1;
	}
	for(int i=0,j;i<L;i++)
		for(int k=0;k<2;k++)
		{
			for(j=i;j!=-1&&(w>>j&1)!=k;j=next[j]);
			tr[i][k]=j+1;
		}
	tr[L][0]=tr[L][1]=L;
}

void gauss()
{
	int i,j,k;
	for(i=j=0;i<S&&j<n;i++)
	{
		for(k=j;k<n;k++)
			if(a[k]>>i&1)break;
		if(k<n)swap(a[j],a[k]);
		else continue;
		for(k=0;k<n;k++)
			if(k!=j&&a[k]>>i&1)a[k]^=a[j];
		j++;
	}
	m=j;
}

inline int check(LL t)
{
	register int i,p=0;
	for(i=0;i<S;i++,t>>=1)
		p=tr[p][t&1];
	return p==L;
}

void workSmall()
{
	LL t;
	for(int s=0;s<(1<<m);s++)
	{
		t=0;
		for(int i=0;i<n;i++)
			if(s>>i&1)t^=a[i];
		ans+=LL(check(t))<<n-m;
	}
	cout<<ans<<endl;
}

int pos[45],cur[45],pre[45];
typedef LL Array[41];
Array f_[1<<17],g_[1<<17];

inline int trans(register int s,register int l,register int p)
{
	while(l--)
		p=tr[p][s&1],s>>=1;
	return p;
}

void workLarge()
{
	for(int i=0,j;i<m;i++)
	{
		for(j=0;j<S;j++)
			if(a[i]>>j&1LL)break;
		pos[i]=j;
		cur[j]=-1;
	}
	pos[m]=S;
	r=0;
	for(int i=0;i<S;i++)
		if(cur[i]!=-1)
			cur[i]=r++;
		else
			pre[i]=r;
	for(int i=0;i<n;i++)
		for(int j=0;j<S;j++)
			if(cur[j]!=-1)
				b[i]|=(a[i]>>j&1LL)<<cur[j];
	Array *f=f_,*g=g_;
	f[0][0]=1;
	LL t;
	for(register int i=0,j,k,l,s0,s1;i<m;i++)
	{
		for(j=0;j<1<<r;j++)
		{
			l=pos[i+1]-pos[i];
			s0=((j>>pre[pos[i]])<<1)&(1<<l)-1;
			s1=((((j^b[i])>>pre[pos[i]])<<1)&(1<<l)-1)|1;
			for(k=0;k<=L;k++)
				if(t=f[j][k])
				{
					g[j][trans(s0,l,k)]+=t;
					g[j^b[i]][trans(s1,l,k)]+=t;
					f[j][k]=0;
				}
		}
		swap(f,g);
	}
	for(int j=0;j<1<<r;j++)
		ans+=f[j][L];
	cout<<(ans<<n-m)<<endl;
}
//#include<ctime>
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	init();
	gauss();
	if(m<=22)
		workSmall();
	else
		workLarge();
	//cout<<clock()<<endl;
	return 0;
}

