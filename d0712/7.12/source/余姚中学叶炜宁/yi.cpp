#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
int n,mi;
char s[300010];
ll ans;
struct hugeint
{
	int len,a[2010];
	hugeint()
	{
		len=0;
		memset(a,0,sizeof(a));
	}
}A;
hugeint operator *(hugeint a,int b)
{
	int x=0;
	for (int i=1;i<=a.len;i++)
	{
		int t=a.a[i]*b+x;
		x=0;
		while (t>=(1<<28))
		{
			x++;
			t-=(1<<28);
		}
		a.a[i]=t;
	}
	if (x) a.a[++a.len]=x;
	while (a.len>1&&a.a[a.len]==0) a.len--;
	return a;
}
hugeint operator +(hugeint a,int b)
{
	a.a[1]+=b;
	for (int i=1;i<=a.len;i++)
	{
		if (a.a[i]>=(1<<28))
		{
			a.a[i+1]++;
			a.a[i]-=(1<<28);
		}else break;
	}
	if (a.a[a.len+1]) a.len++;
	while (a.len>1&&a.a[a.len]==0) a.len--;
	return a;
}
hugeint operator /(hugeint a,int b)
{
	ll x=0;
	for (int i=a.len;i>=1;i--)
	{
		ll t=(x<<28)+a.a[i];
		a.a[i]=t/b;
		x=t%b;
	}
	while (a.len>1&&a.a[a.len]==0) a.len--;
	return a;
}
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",s);n=strlen(s);
	A.len=n/28;if (n%28) A.len++;
	for (int i=0;i<n;i++)
		if (s[n-i-1]=='1') A.a[i/28+1]|=1<<(i%28);
	while (A.len>1||A.a[1]>1)
	{
		if (A.a[1]&1){A=A*3+1;ans++;}else
		{
			while (!(A.a[1]&1))
			{
				mi=1;
				while ((mi<(1<<28))&&(!(A.a[1]&mi))){mi<<=1;ans++;}
				A=A/mi;
			}
		}
	}
	printf("%lld\n",ans);
}
