#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <time.h>
using namespace std;
char s[333333];
typedef long long ll;
#define P 61
#define G 2305843009213693952LL
struct hp {int n; ll s[666666];}; 
void yd(hp& s)
{
	while(s.n&&!s.s[s.n]) --s.n;
}
void mul2(hp& a,hp& t)
{
	t.n=a.n+1;
	for(int i=1;i<=a.n;i++) t.s[i]=a.s[i]<<1;
	t.s[t.n]=0;
	for(int i=1;i<=t.n;i++)
	{
		t.s[i+1]+=t.s[i]>>P;
		t.s[i]&=G-1;
	}
	yd(t);
}
void div2(hp& a)
{
	ll lst=0;
	for(int i=a.n;i>=1;i--)
	{
		long long t=lst+(a.s[i]>>1);
		if(a.s[i]&1) lst=G>>1; else lst=0;
		a.s[i]=t;
	}
	yd(a);
}
inline void aas(hp& a,hp& b)
{
	int nn=max(a.n,b.n)+2;
	for(int i=a.n+1;i<=nn;i++) a.s[i]=0;
	a.n=nn;
	for(int i=1;i<=b.n;i++) a.s[i]+=b.s[i];
	a.s[1]++;
	for(int i=1;i<=a.n;i++)
	{
		a.s[i+1]+=a.s[i]>>P;
		a.s[i]&=G-1;
	}
	yd(a);
}
hp yl,yl2;
int tmp[2333333];
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	gets(s); int sn=strlen(s);
	reverse(s,s+sn);
	for(int i=0;i<sn;i++) tmp[i]=s[i]-48;
	yl.n=sn/P+1;
	for(int i=1;i<=yl.n;i++)
	{
		ll ans=0;
		for(int p=-1;p>=-P;p--) ans=ans*2+tmp[i*P+p];
		yl.s[i]=ans;
	}
	long long ans=0;
	while(yl.n!=1||yl.s[1]!=1)
	{
		if(yl.s[1]&1)
		{
			++ans;
			mul2(yl,yl2);
			aas(yl,yl2);
		}
		else
		{
			++ans;
			div2(yl);
		}
	}
	cout<<ans<<"\n";
}
