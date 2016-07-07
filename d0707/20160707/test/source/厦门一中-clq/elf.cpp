#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define nMax 42
using namespace std;
int n,len;
long long a[nMax],m,h;
char s[nMax];
void work()
{
	int now=1;
	for(int i=39;i>=0;i--)
	{
		int ls=now;
		while(ls<=n&&(a[ls]&((long long)1<<i))==0) ls++;
		if(ls>n) continue;
		swap(a[now],a[ls]);
		for(int j=1;j<=n;j++)
		if((a[j]&((long long)1<<i))&&j!=now) a[j]^=a[now];
		now++;
	}
	now--;
	int _en=(1<<now);
	long long ans=0;
	for(int i=0;i<_en;i++)
	{
		long long ls=0;
		for(int j=1;j<=n;j++) if(i&((long long)1<<j>>1)) ls^=a[j];
		int flag=0;
		for(int j=0;j<=40-len;j++)
		if((ls&(h<<j))==(m<<j)) {flag=1; break;}
		if(flag) ans+=(long long)1<<(n-now);
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<40;j++)
		{
			a[i]<<=1;
			if(s[j]=='1') a[i]|=1;
		}
	}
	scanf("%d",&len);
	scanf("%s",s);
	for(int j=0;j<len;j++)
	{
		m<<=1; h<<=1;
		if(s[j]=='1') m|=1;
		h|=1;
	}
	work();
	return 0;
}
