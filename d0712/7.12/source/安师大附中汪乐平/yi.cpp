#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<bitset>
using namespace std;
struct node
{
	int n,a[300005];
}x;
char c[300005];
int n,i,m,o[65536];
inline int O(int x)
{
	if(x&65535)return o[x&65535];
	return 16+o[x>>16];
}
void fix(bool b)
{
	int i,j,k,l;
	if(b)
	{
		m++;
		for(i=0;i<x.n;i++)x.a[i]+=x.a[i]<<1;
		x.a[0]++;
		for(i=0;i<x.n;i++)if(x.a[i]>536870911)
		{
			x.a[i+1]+=x.a[i]>>29;
			x.a[i]&=536870911;
		}
		for(;x.a[i];i++)
		{
			x.a[i+1]=x.a[i]>>29;
			x.a[i]&=536870911;
		}
		x.n=i;
	}
	else
	{
		for(i=0;i<x.n;i++)if(x.a[i])break;
		k=O(x.a[i]);
		l=(1<<k)-1;
		m+=i*29+k;
		for(j=0;j+i<x.n;j++)x.a[j]=x.a[i+j]>>k|(x.a[i+j+1]&l)<<29-k;
		for(;j<x.n;j++)x.a[j]=0;
		x.n-=i;
		if(!x.a[x.n-1])x.n--;
	}
}
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	for(i=2;i<65536;i++)if(!(i&1))o[i]=o[i>>1]+1;
	scanf("%s",c);
	n=strlen(c);
	reverse(c,c+n);
	for(i=0;i<n;i++)x.a[i/29]|=(c[i]^'0')<<(i%29);
	x.n=(n+28)/29;
	if(!(x.a[0]&1))fix(0);
	for(i=0;x.n!=1||x.a[0]!=1;i++)
	{
		fix(1);
		fix(0);
	}
	printf("%d\n",m);
	return 0;
}

