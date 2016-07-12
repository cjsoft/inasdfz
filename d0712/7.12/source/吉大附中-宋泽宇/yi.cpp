#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define L 30
#define ui unsigned int
#define ll unsigned long long
const ui mod=1<<L;
char s[310000];
int ans;
struct node
{
	int a[31000],len;
	void mul(ui x)
	{
		ui t=0;
		for(int i=0;i<=len;i++)
		{
			ll tmp=a[i]*x+t;
			a[i]=tmp%mod;t=tmp/mod;
		}
		if(t)a[++len]=t;
	}
	void add(ui x)
	{
		a[0]+=x;
		for(int i=0;i<=len;i++)
			if(a[i]>=mod)
			{a[i]-=mod;a[i+1]++;}
		if(a[len+1])len++;
	}
	void rm()
	{
		while(!(a[0]&1))
		{
			for(int i=0;i<=len;i++)
				a[i]=(a[i]>>1)+((a[i+1]&1)<<L-1);
			if(!a[len])len--;
			ans++;
		}
	}
}v;
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",s);int len=strlen(s);
	reverse(s,s+len);
	for(int i=0;i<len;i++)
	{
		if(s[i]=='1')v.a[v.len]+=1<<i%L;
		if(i%L==L-1)v.len++;
	}
	if(!v.a[v.len])v.len--;
	while(v.a[0]!=1||v.len!=0)
	{
		if(v.a[0]&1)v.mul(3),v.add(1),ans++;
		else v.rm();
	}
	printf("%d\n",ans);
	return 0;
}
