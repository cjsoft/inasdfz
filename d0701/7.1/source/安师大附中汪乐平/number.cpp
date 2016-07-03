#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define L 50
#define MAXN 1100000
#define base 233
#define ll long long
struct node
{
	int a[L],h,l;
}q[MAXN];
int he,ta=2,n,i,j=2,k,l,m,t[L],o[100000];
inline void add(int *a,const int *b)
{
	register int i,j;
	a[0]=max(a[0],b[0]);
	for(i=1,j=0;i<=a[0];i++)
	{
		a[i]+=b[i]+j;
		j=a[i]>>16;
		a[i]&=65535;
	}
	for(;a[0]+1<L&&j;j>>=16)a[++a[0]]=j&65535;
}
inline void mul(int *a,int b)
{
	register int i,j;
	for(i=1,j=0;i<=a[0];i++)
	{
		a[i]=a[i]*b+j;
		j=a[i]>>16;
		a[i]&=65535;
	}
	for(;a[0]+1<L&&j;j>>=16)a[++a[0]]=j&65535;
}
inline int get(int *a,int n)
{
	register int i=0,j=0;
	for(;i<(n-1>>4);i++)j+=o[a[i+1]];
	j+=o[a[i+1]&((1<<((n-1&15)+1))-1)];
	return j;
}
inline void out(int x,int y)
{
	if(y)out(x>>1,y-1);
	putchar((x&1)^'0');
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(i=1;i<65536;i++)o[i]=o[i>>1]+(i&1);
	n--;
	if(!n)
	{
		cout<<1<<endl;
		return 0;
	}
	t[0]=t[1]=q[0].l=q[0].a[0]=q[1].l=q[1].a[0]=q[1].a[1]=q[1].h=1;
	for(;;he=ta,ta=j)for(mul(t,10),k=0;k<2;k++)for(i=he;i<ta;i++)
	{
		q[j]=q[i];
		q[j].l++;
		q[j].h+=k;
		if(k)add(q[j].a,t);
		if(q[j].h==get(q[j].a,q[j].l))
		{
			if(k)if(!--n)
			{
				out(q[j].a[(q[j].l-1>>4)+1],q[j].l-1&15);
				for(l=q[j].l-1>>4;l;l--)out(q[j].a[l],15);
				putchar('\n');
				return 0;
			}
			j++;
		}
	}
	return 0;
}

