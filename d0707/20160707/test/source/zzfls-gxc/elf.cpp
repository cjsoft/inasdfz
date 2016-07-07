#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;
int n,L;
ll a[25],b;
char ch[45];
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",ch);
		a[i]=0;
		for(int j=0;j<40;++j)
			a[i]<<=1,a[i]|=(ch[j]-'0');
	}
	scanf("%d%s",&L,ch);
	b=0;
	for(int j=0;j<L;++j)
		b<<=1,b|=(ch[j]-'0');
	int m=1<<n,p=(1<<L)-1,ans=0;
	bool fl=0;
	ll Now;
	for(int i=0;i<m;++i)
	{
		Now=0;fl=0;
		for(int j=1;j<=n;++j)
			if(i&(1<<(j-1))) Now^=a[j];
		for(int j=0;j<=40-L;++j)
		{
			if((Now&p)==b) fl=1;
			Now>>=1;
		}
		if(fl) ans++;
	}
	printf("%d",ans);
	return 0;
}

